#ifndef __BiNARY_SEARCH_TREE_H__
#define __BiNARY_SEARCH_TREE_H__

#include "BinaryTree.h"
typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode * bst);

void BSTInsert(BTreeNode ** pRoot, BSTData data);

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// 노드 삭제
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

void BSTShowAll(BTreeNode * bst);

#endif