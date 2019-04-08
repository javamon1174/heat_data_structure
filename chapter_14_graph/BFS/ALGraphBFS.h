#ifndef __AL_GRAPH_BFS_H__
#define __AL_GRAPH_BFS_H__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    int * visitInfo;
    List * adjList;
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV); // V => Vertex

void BFShowGraphVertex(ALGraph * pg, int startV);

void ShowGraphEdgeInfo(ALGraph * pg);

#endif