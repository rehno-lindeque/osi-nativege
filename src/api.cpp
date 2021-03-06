//////////////////////////////////////////////////////////////////////////////
//
//    API.CPP
//
//    Copyright © 2006, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////
/*                               DOCUMENTATION                              */
/*
    DESCRIPTION:
*/
/*                              COMPILER MACROS                             */
#pragma warning(push)
#pragma warning(disable:4311)
#pragma warning(disable:4312)

/*                                 INCLUDES                                 */
// NativeGE
#include "api.h"

using namespace NativeGE;
using namespace BaseGE;
/*                                  GLOBALS                                 */

/*                               IMPLEMENTATION                             */

/* elements */
OSobject geBeginElements(OS_BASIC_TYPE type)
{
  Elements* elementsObject = beginObject<Elements>();
  elementsObject->init(type);
  return cast_object(elementsObject);
}

void geEndElements()
{
  Elements* elementsObject = endObject<Elements>();
}

void geOpenElements(OSobject elements)
{
  Elements* elementsObject = openObject<Elements>(elements);
}

void geCloseElements()
{
  Elements* elementsObject = closeObject<Elements>();
}

void geAddElements(OSuint nElements, void* elements)
{
  Elements* elementsObject = getActiveObject<Elements>();
  elementsObject->add(nElements, elements);
}

/* geometry pool */
OSobject geBeginGeometryPool()
{
  NativeGeometryPool* geometryPoolObject = beginObject<NativeGeometryPool>();
  return cast_object(geometryPoolObject);
}

void geEndGeometryPool()
{
  NativeGeometryPool* geometryPoolObject = endObject<NativeGeometryPool>();
  geometryPoolObject->calculateBoundingBox();
}

void geOpenGeometryPool(OSobject geometryPool)
{
  NativeGeometryPool* geometryPoolObject = openObject<NativeGeometryPool>(geometryPool);
}

void geCloseGeometryPool()
{
  NativeGeometryPool* geometryPoolObject = closeObject<NativeGeometryPool>();
  //todo: geometryPoolObject->calculateBoundingBox(); (or recalculate rather)
}

void geGeometry(OSobject geometry)
{
  //todo?
}

/* geometry frame */
OSobject geBeginFrame()
{
  Frame* frameObject = beginObject<Frame>();
  return cast_object(frameObject);
}

void geEndFrame()
{
  Frame* frameObject = endObject<Frame>();
}

void geOpenFrame(OSobject frame)
{
  Frame* frameObject = openObject<Frame>(frame);
}

void geCloseFrame()
{
  Frame* frameObject = closeObject<Frame>();
}

void geClearFrame()
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geTransformFrame(OSfloat* matrix)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geTranslateFrame(OSfloat x, OSfloat y, OSfloat z)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geTranslateFrame(OSfloat* v)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geRotateFrame(OSfloat angle, OSfloat x, OSfloat y, OSfloat z)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geScaleFrame(OSfloat x, OSfloat y, OSfloat z)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

void geScaleFrame(OSfloat* v)
{
  Frame* frameObject = getActiveObject<Frame>();
  //todo
}

/* geometry instance */
void geBeginGeometryInstanceData(OSobject geometry)
{
  //todo
}

void geEndGeometryInstanceData()
{
  //todo
}

OSid geAddGeometryInstance(OSobject geometry, GE_GEOMETRY_STABILITY stability)
{
  NativeGeometryPool* geometryPoolObject = getActiveObject<NativeGeometryPool>();
  NativeGeometry* geometryObject = cast_id<NativeGeometry>(geometry);
  OSid instance = geometryPoolObject->addGeometryInstance(geometryObject, stability);
  return instance;
}

void geRemoveGeometryInstance(OSid geometryInstance)
{
  NativeGeometryPool* geometryPoolObject = getActiveObject<NativeGeometryPool>();
  OSuint index = (OSuint)geometryInstance;
  geometryPoolObject->removeGeometryInstance(index);
}

/* geometry */
OSobject geBeginGeometry(GE_GEOMETRY type)
{
  NativeGeometry* geometryObject = beginObject<NativeGeometry>();
  return cast_object(geometryObject);
}

void geEndGeometry()
{
  NativeGeometry* geometryObject = endObject<NativeGeometry>();
  geometryObject->build();
}

void gePoints(OSobject points)
{
  NativeGeometry* geometryObject = getActiveObject<NativeGeometry>();
  geometryObject->addPoints(cast_id<NativePoints>(points));
}

void geLines(OSobject lines)
{
  NativeGeometry* geometryObject = getActiveObject<NativeGeometry>();
  geometryObject->addLines(cast_id<NativeLines>(lines));
}

void geTriangles(OSobject triangles)
{
  NativeGeometry* geometryObject = getActiveObject<NativeGeometry>();
  geometryObject->addTriangles(cast_id<NativeTriangles>(triangles));
}

void geQuads(OSobject quads)
{
  NativeGeometry* geometryObject = getActiveObject<NativeGeometry>();
  geometryObject->addQuads(cast_id<NativeQuads>(quads));
}

void gePolygons(OSobject polygons)
{
  NativeGeometry* geometryObject = getActiveObject<NativeGeometry>();
  geometryObject->addPolygons(cast_id<NativePolygons>(polygons));
}

/* geometric components */
OSobject geBeginPoints()
{
  NativePoints* pointsObject = beginObject<NativePoints>();
  return cast_object(pointsObject);
}

void geEndPoints()
{
  NativePoints* pointsObject = endObject<NativePoints>();
}

OSobject geBeginLines()
{
  NativeLines* linesObject = beginObject<NativeLines>();
  return cast_object(linesObject);
}

void geEndLines()
{
  NativeLines* linesObject = endObject<NativeLines>();
}

OSobject geBeginTriangles()
{
  NativeTriangles* trianglesObject = beginObject<NativeTriangles>();
  return cast_object(trianglesObject);
}

void geEndTriangles()
{
  NativeTriangles* trianglesObject = endObject<NativeTriangles>();
}

OSobject geBeginQuads()
{
  NativeQuads* quadsObject = beginObject<NativeQuads>();
  return cast_object(quadsObject);
}

void geEndQuads()
{
  NativeQuads* quadsObject = beginObject<NativeQuads>();
}

OSobject geBeginPolygons()
{
  NativePolygons* polygonsObject = beginObject<NativePolygons>();
  return cast_object(polygonsObject);
}

void geEndPolygons()
{
  NativePolygons* polygonsObject = endObject<NativePolygons>();
}

/* sub-components */
void geVertexData(OSobject vertexData)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->vertexData = cast_id<NativeVertexData>(vertexData);
}

void geVertices(OSobject vertices)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->vertices = cast_id<NativeVertices>(vertices);
}

void geEdgeData(OSobject edgeData)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->edgeData = cast_id<NativeEdgeData>(edgeData);
}

void geEdges(OSobject edges)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->edges = cast_id<NativeEdges>(edges);
}

void gePrimitiveData(OSobject primitiveData)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->primitiveData = cast_id<NativePrimitiveData>(primitiveData);
}

void gePrimitives(OSobject primitives)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->primitives = cast_id<NativePrimitives>(primitives);
}

void geSurfaceData(OSobject surfaceData)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->surfaceData = cast_id<NativeSurfaceData>(surfaceData);
}

void geSurfaces(OSobject surfaces)
{
  Components* componentsObject = getActiveObject<Components>();
  componentsObject->surfaces = cast_id<NativeSurfaces>(surfaces);
}

/* indexing components */
OSobject geBeginVertices(OSuint nVertices)
{
  NativeVertices* verticesObject = beginObject<NativeVertices>();
  return cast_object(verticesObject);
}

void geEndVertices()
{
  NativeVertices* verticesObject = endObject<NativeVertices>();
}

OSobject geBeginEdges(OSuint nEdges)
{
  NativeEdges* edgesObject = beginObject<NativeEdges>();
  return cast_object(edgesObject);
}

void geEndEdges()
{
  NativeEdges* edgesObject = endObject<NativeEdges>();
}

OSobject geBeginPrimitives(OSuint nPrimitives)
{
  NativePrimitives* primitivesObject = beginObject<NativePrimitives>();
  return cast_object(primitivesObject);
}

void geEndPrimitives()
{
  NativePrimitives* primitivesObject = endObject<NativePrimitives>();
}

OSobject geBeginSurfaces(OSuint nSurfaces)
{
  NativeSurfaces* surfacesObject = beginObject<NativeSurfaces>();
  return cast_object(surfacesObject);
}

void geEndSurfaces()
{
  NativeSurfaces* surfacesObject = endObject<NativeSurfaces>();
}


/* data components*/
OSobject geBeginVertexData(OSuint n)
{
  NativeVertexData* vertexData = beginObject<NativeVertexData>();
  return cast_object(vertexData);
}

void geEndVertexData()
{
  NativeVertexData* vertexData = endObject<NativeVertexData>();
}

OSobject geBeginEdgeData(OSuint n)
{
  NativeEdgeData* edgeData = beginObject<NativeEdgeData>();
  return cast_object(edgeData);
}

void geEndEdgeData()
{
  NativeEdgeData* edgeData = endObject<NativeEdgeData>();
}

OSobject geBeginPrimitiveData(OSuint n)
{
  NativePrimitiveData* primitiveData = beginObject<NativePrimitiveData>();
  return cast_object(primitiveData);
}

void geEndPrimitiveData()
{
  NativePrimitiveData* primitiveData = endObject<NativePrimitiveData>();
}

OSobject geBeginSurfaceData(OSuint n)
{
  NativeSurfaceData* surfaceData = beginObject<NativeSurfaceData>();
  return cast_object(surfaceData);
}

void geEndSurfaceData()
{
  NativeSurfaceData* surfaceData = endObject<NativeSurfaceData>();
}

/* indexing */
/*void geIndices(OSobject indexElements)
{
}

void geComponentCounts(OSobject countElements)
{
}*/

/* attributes */
void geAttributes(OSenum attribute, OSobject elements)
{
  AttributeObject* object = (AttributeObject*)activeObjects.top();
  object->setAttribute(attribute, elements);
}

/* miscelaneous */
void geDelObject(OSobject object)
{
  delObject((Object*)object);
}

void geShutdown()
{
  shutdown();
}

/*                              COMPILER MACROS                             */
#pragma warning(pop)
