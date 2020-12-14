#pragma once
#include "Node.h"
class BinarySearchTree
{
public:
	Node* root;
	BinarySearchTree() { root = nullptr; }
	void insert( int key);
	void InOrder(Node* t);
	Node * Rinsert(Node* t, int key);
	Node * Delete(Node *p,int key);
	int Height(Node* t);
	Node* Inpre(Node* t);
	Node* InSucc(Node* t);
	void deleteNodes(Node* t);
	~BinarySearchTree() { deleteNodes(root); }
};

