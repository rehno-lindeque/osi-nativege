#ifndef __NATIVEGE_API_H__
#define __NATIVEGE_API_H__
//////////////////////////////////////////////////////////////////////////////
//
//    API.H
//
//    Author:      Rehno Lindeque
//
//    Description: NativeGE classes used to implement api
//
//    Version: 0.1 (informal prototype)
//
//    Copyright © 2006, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

/*                                   INCLUDES                               */
// BaseGE
#include <basege/basege.h>

/*                               COMPILER MACROS                            */
#pragma warning(push)
#pragma warning(disable:4311)
#pragma warning(disable:4312)

/*                             FORWARD DECLERATIONS                         */
namespace NativeGE
{
  class NativePoints;
  class NativeLines;
  class NativeTriangles;
  class NativeQuads;
  class NativePolygons;
  class NativeVertexData;
  class NativeEdgeData;
  class NativePrimitiveData;
  class NativeSurfaceData;
  class NativeVertices;
  class NativeEdges;
  class NativePrimitives;
  class NativeSurfaces;
  class NativeGeometry;
  class NativeGeometryPool;
}

/*                                   INCLUDES                               */
// NativeGE
#include "points.h"
#include "lines.h"
#include "triangles.h"
#include "quads.h"
#include "polygons.h"
#include "vertexdata.h"
#include "edgedata.h"
#include "primitivedata.h"
#include "surfacedata.h"
#include "vertices.h"
#include "edges.h"
#include "primitives.h"
#include "surfaces.h"
#include "geometry.h"
#include "geometrypool.h"

namespace NativeGE
{
/*                                CONSTANTS                                 */
/*                                 GLOBALS                                  */
/*                              COMPILER MACROS                             */
#pragma warning(pop)
}

#endif
