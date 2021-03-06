#ifndef __NATIVEGE_GEOMETRYPOOL_H__
#define __NATIVEGE_GEOMETRYPOOL_H__
//////////////////////////////////////////////////////////////////////////////
//
//    GEOMETRYPOOL.H
//
//    Copyright © 2006, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////
/*                               DOCUMENTATION                              */
/*
    DESCRIPTION:
      NativeGE GeometryPool

    TODO:
      + Clean up primitive \ component convention
*/

using BaseGE::cast_id;

namespace NativeGE
{
/*                                  CLASSES                                 */
  class NativeGeometryPool : public BaseGE::GeometryPool
  {
  protected:
    AxisAlignedBoundingBox boundingBox;
    void* structData;
    void* primitiveData;

    enum BIH_AXIS
    {
      X_AXIS = 0x0,
      Y_AXIS = 0x1,
      Z_AXIS = 0x2
    };

    enum BIH_NODE_TYPE
    {
      X_AXIS_SPLIT = 0x0,
      Y_AXIS_SPLIT = 0x1,
      Z_AXIS_SPLIT = 0x2,
      LEAF         = 0x3
    };

    enum BIH_UNPACK_FUNCTION
    {
      LEFT_COMPONENTS,
      //MIDDLE_LEFT_COMPONENTS,
      //MIDDLE_RIGHT_COMPONENTS,
      MIDDLE_COMPONENTS,
      RIGHT_COMPONENTS
    };

    struct BIH_SplittingPlane
    {
      BIH_AXIS axis;
      float position;
    };

    struct BIH_NodeHeader
    {
      BIH_NODE_TYPE nodeType;
      union
      {
        struct
        {
          OSfloat leftBoundary;
          OSfloat rightBoundary;
        };
        OSfloat boundaries[2];
      };
      OSuint32 rightOffset;
     };

    struct BIH_LeafNodeHeader
    {
      BIH_NODE_TYPE nodeType;
      OSuint32 primitiveOffset;
      OSuint32 nPrimitives;
      OSuint32 reserved;
     };

    struct BIH_ConstructionNode
    {
      AxisAlignedBoundingBox boundingBox;
      BIH_SplittingPlane splittingPlane;

      float* leftConstructionPosition;
      float* rightConstructionPosition;

      union
      {
        BIH_NodeHeader* nodeHeader;
        BIH_LeafNodeHeader* leafHeader;
      };

      inline BIH_ConstructionNode()
      {
        nodeHeader = 0;
      }
    };

    struct BIH_FineNode : public BIH_ConstructionNode
    {};

    struct BIH_CoarseNode : public BIH_ConstructionNode
    {
      std::list<OSobject> leftGeometryInstances;
      std::list<OSobject> middleGeometryInstances;
      std::list<OSobject> rightGeometryInstances;

      OSuint nLeftPrimitives;
      OSuint nMiddlePrimitives;
      OSuint nRightPrimitives;

      // todo: remove dynamic creation of nodes and put it on the stack instead
      //BIH_ConstructionNode* leftNode;
      //BIH_ConstructionNode* rightNode;

      float* middleLeftConstructionPosition;
      float* middleRightConstructionPosition;
      //float* middleMiddleConstructionPosition;

      inline BIH_CoarseNode()
      {
        nLeftPrimitives = 0;
        nRightPrimitives = 0;
        nMiddlePrimitives = 0;
        //leftNode = 0;
        //rightNode = 0;
      }
    };
    void* structConstructionPosition;
    void* primitiveConstructionPosition;

    inline void BIH_getSplittingPlane(BIH_SplittingPlane& splittingPlane, const AxisAlignedBoundingBox& boundingBox);

    template<BIH_UNPACK_FUNCTION unpack> inline void BIH_UnpackTriangle(BIH_CoarseNode& node, const Vector3f& v1, const Vector3f& v2, const Vector3f& v3);
    template<BIH_UNPACK_FUNCTION unpack> inline void BIH_UnpackInstance(BIH_CoarseNode& node, GeometryInstance* geometryInstance);
    template<BIH_UNPACK_FUNCTION unpack> inline void BIH_UnpackComponents(BIH_CoarseNode& node);

    inline void BIH_InsertInstance(BIH_CoarseNode& node, GeometryInstance* geometryInstance);

    inline void swapTriangles(float* triangle1, float* triangle2);

    inline void BIH_BuildFineNode(BIH_FineNode& node);

    inline void BIH_RefineCoarseNode(BIH_CoarseNode& node, std::list<OSobject>& geometryInstances);
    inline void BIH_BuildCoarseNode(BIH_CoarseNode& node);

    inline void BIH_BuildRootNode(BIH_CoarseNode& rootNode);

    inline OSid BIH_rebuild();
    inline OSid BIH_build();

  public:
    inline NativeGeometryPool() {}

    inline ~NativeGeometryPool()
    {
      //todo: destroy structures
    }

    inline AxisAlignedBoundingBox calculateBoundingBox();

    inline OSid getStructure(GE_HARDWARE_INTERFACE hardwareInterface, GE_SPATIAL_STRUCTURE structure, GE_STRUCTURE_LAYOUT structureLayout, GE_PRIMITIVE_LAYOUT primitiveLayout)
    {
      OSid spatialStructure = findStructure(hardwareInterface, structure);
      if(spatialStructure == 0)
      {
        // create the structure
        switch(structure)
        {
        case GE_BIH:
          spatialStructure = BIH_build();
          break;
        }
      }
      else
      {
        // rebuild the structure
        switch(structure)
        {
        case GE_BIH:
          spatialStructure = BIH_rebuild();
          break;
        }
      }

      return spatialStructure;
    }

    inline const float* getBoundingBox() const { return (const float*)boundingBox; }
  };
}

/*                              IMPLEMENTATION                              */
#include "geometrypool.hxx"

#endif
