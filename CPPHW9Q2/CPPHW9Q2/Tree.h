#pragma once
#include <iostream>
#include <math.h>
#include "QueueVector.h"

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	int height() const { return height(root); }
	void reflect() { reflect(root); }
	void BreadthScan();

	virtual void process(T val) { std::cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int height(Node* current) const;
	void BreadthScan(Node* current, QueueVector<typename Tree<T>::Node*> Q);
	void reflect(Node* current);

};
//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template <class T>
int Tree<T>::height(Node* current) const
{
	if (current == nullptr)
		return -1;
	int l = height(current->left),
		r = height(current->right);

	return 1 + ((l > r) ? l : r);
}

template <class T>
void Tree<T>::reflect(Node* current) {
	if (current == nullptr)
		return;

	reflect(current->left);
	reflect(current->right);

	Node* tmp = current->left;
	current->left = current->right;
	current->right = tmp;	
}
template <class T>
void Tree<T>::BreadthScan() {
	int h = height();
	int nodes = pow(2, h);

	QueueVector<typename Tree<T>::Node*> Q(nodes);

	BreadthScan(Tree<T>::root, Q);
}

template <class T>
void Tree<T>::BreadthScan(Node* current, QueueVector<typename Tree<T>::Node*> Q) {
	if (current == nullptr)
		return;
	process(current->value);
	if (current->left != nullptr) {
		Q.enqueue(current->left);
	}
	if (current->right != nullptr) {
		Q.enqueue(current->right);
	}
	
	if (!Q.isEmpty()) {
		Tree<T>::Node* node = Q.dequeue();
		BreadthScan(node, Q);
	}
}