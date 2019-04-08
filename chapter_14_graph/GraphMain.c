#include <stdio.h>

// 무방향 그래프
//#include "ALGraph.h"
//#include "ALGraph.c"

// DFS(Depth First Search) : Stack(경로 정보 추적 용도), Array(방문 정보 기록 용도)
//#include "DFS/ALGraphDFS.h"
//#include "DFS/ALGraphDFS.c"

// BFS(Breadth First Search) : Queue(방문 차례 기록 용도), Array(방문 정보 기록 용도)
//#include "BFS/ALGraphBFS.h"
//#include "BFS/ALGraphBFS.c"

// 최소비용 신장트리
#include "Kruskal/AlGraphKruscal.h"
#include "Kruskal/AlGraphKruscal.c"

void GraphMain()
{
    /*
     * 무방향 그래프
    ALGraph graph;
    GraphInit(&graph, 5);     // A, B, C, D, E의 정점 생성

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);

    ShowGraphEdgeInfo(&graph);

    GraphDestroy(&graph);
    */

    /*
     * DFS(Depth First Search) : Stack(경로 정보 추적 용도), Array(방문 정보 기록 용도)

    ALGraph graph;
    GraphInit(&graph, 7);      // A, B, C, D, E, F, G�� ���� ����

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, A); printf("\n");
    DFShowGraphVertex(&graph, C); printf("\n");
    DFShowGraphVertex(&graph, E); printf("\n");
    DFShowGraphVertex(&graph, G); printf("\n");

    GraphDestroy(&graph);
    */
    /*
     * BFS(Breadth First Search) : Queue(방문 차례 기록 용도), Array(방문 정보 기록 용도)

    ALGraph graph;
    GraphInit(&graph, 7);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    BFShowGraphVertex(&graph, A); printf("\n");
    BFShowGraphVertex(&graph, C); printf("\n");
    BFShowGraphVertex(&graph, E); printf("\n");
    BFShowGraphVertex(&graph, G); printf("\n");

    GraphDestroy(&graph);
    */

    // 최소비용 신장트리
    ALGraph graph;
    GraphInit(&graph, 6);      // A, B, C, D, E, F, G의 정점 생성

    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, B, C, 2);
    AddEdge(&graph, A, C, 12);
    AddEdge(&graph, A, D, 8);
    AddEdge(&graph, D, C, 6);
    AddEdge(&graph, A, F, 11);
    AddEdge(&graph, F, D, 4);
    AddEdge(&graph, D, E, 3);
    AddEdge(&graph, E, C, 7);
    AddEdge(&graph, F, E, 13);

    ConKruskalMST(&graph);
    ShowGraphEdgeInfo(&graph);
    ShowGraphEdgeWeightInfo(&graph);

    GraphDestroy(&graph);
}