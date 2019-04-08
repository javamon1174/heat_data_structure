#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;
    PQueue pqueue;
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

void DFShowGraphVertex(ALGraph * pg, int startV);

void ShowGraphEdgeInfo(ALGraph * pg);

// 최소 비용 신장트리 구성 - 크루스칼
void ConKruskalMST(ALGraph * pg);

void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif