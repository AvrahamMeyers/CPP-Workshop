#pragma once
#include "Tree.h"
#include <iostream>

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T value);
	void deleteDuplicates();
	T successor(T value);

private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* successor(typename Tree<T>::Node* node);
	typename Tree<T>::Node* Min(typename Tree<T>::Node* current);
	typename Tree<T>::Node* searchNode(typename Tree<T>::Node* current, T value);
	typename Tree<T>::Node* findParent(typename Tree<T>::Node* node);
	typename Tree<T>::Node* findParent(typename Tree<T>::Node* node, typename Tree<T>::Node* root);
	void remove(typename Tree<T>::Node* node);
	void deleteDuplicateNodes(typename Tree<T>::Node* node);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
template <class T>
typename Tree<T>::Node* SearchTree<T>::Min(typename Tree<T>::Node* current) {
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::successor(typename Tree<T>::Node* node) {
	if (node->right != nullptr)
		return Min(node->right);
	else {
		typename Tree<T>::Node* successor = nullptr;
		typename Tree<T>::Node* current = this->root;

		while (current->value != node->value) {
			if (node->value < current->value) { //if the current value is greater than 
				successor = current;// the value being searched against, then it is a potential successor
				current = current->left;// and any other potential successors would be in the left sub tree
			}
			else
				current = current->right;//otherwise, the potential successor is in the right sub tree
		}
		if (successor == nullptr)
			throw "no successor\n";
		return successor;
	}
}											  
template <class T>
typename Tree<T>::Node* SearchTree<T>::searchNode(typename Tree<T>::Node* current, T value) {
	if (current == nullptr)
		return nullptr;
	if (current->value == value)
		return current;
	if (current->value > value)
		return searchNode(current->left, value);
	else
		return searchNode(current->right, value);
}
template <class T>
void SearchTree<T>::remove(T value) {
	typename Tree<T>::Node* node = searchNode(Tree<T>::root, value);
	remove(node);
}

template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node* node) {
	if (node == nullptr)
		throw "node not in tree\n";
	typename Tree<T>::Node* parent = findParent(node);

	if (node->left == nullptr && node->right == nullptr) {//if the node has no children
		if (parent == nullptr) {//and the node is the root, then just delete the node
			delete node;
			Tree<T>::root = nullptr;//and make the root null
		}
		else {
			if (parent->left == node)//make the parent of the node point to null
				parent->left = nullptr;//instead of the node
			else
				parent->right = nullptr;
			delete node;
		}
	}
	else if (node->left != nullptr && node->right == nullptr) {//if the node only has a left child
		if (parent == nullptr)
			Tree<T>::root = node->left;
		else {
			if (parent->left == node)//point the parent of the node to the left child
				parent->left = node->left;
			else
				parent->right = node->left;
			delete node;
		}
	}
	else if (node->left == nullptr && node->right != nullptr) {//if the node only has a right child
		if (parent == nullptr)
			Tree<T>::root = node->right;
		else {
			if (parent->left == node)//point the parent to the right child
				parent->left = node->right;
			else
				parent->right = node->right;
			delete node;
		}
	}
	else {//if the node has two children, then the successor must be found
		typename Tree<T>::Node* succ = successor(node);
		typename Tree<T>::Node* succParent = findParent(succ);
		typename Tree<T>::Node* newchild = succ->right;

		if (succParent->left == succ)//moving the successors child to the successors place
			succParent->left = newchild;
		else
			succParent->right = newchild;

		if (parent == nullptr) 
			Tree<T>::root = succ;
		else {
			if (parent->left == node)//pointing the parent of the node to the successor
				parent->left = succ;
			else
				parent->right = succ;
		}
		succ->left = node->left;//and making the nodes children the successors children
		succ->right = node->right;
		
		delete node;
	}
}
template <class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* node) {
	return findParent(node, Tree<T>::root);
}
template <class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* node, typename Tree<T>::Node* root) {
	if (root == node)
		return nullptr;
	if (root->right == nullptr && root->left == nullptr)
		throw "node not in tree\n";	
	if (root->right == node || root->left == node)
		return root;
	if (node->value <= root->value)
		return findParent(node, root->left);
	else
		return findParent(node, root->right);
}
template <class T>
void SearchTree<T>::deleteDuplicates() {
	deleteDuplicateNodes(Tree<T>::root);
}
template <class T>
void SearchTree<T>::deleteDuplicateNodes(typename Tree<T>::Node* node) {
	if (node == nullptr)
		return;
	if (node->left != nullptr)
		deleteDuplicateNodes(node->left);

	int h = Tree<T>::height();
	int nodes = pow(2, h);

	QueueVector<typename Tree<T>::Node*> Q(nodes);

	typename Tree<T>::Node* duplicate = searchNode(node->right, node->value);
	if (duplicate != nullptr)
		Q.enqueue(duplicate);
	duplicate = searchNode(node->left, node->value);
	if (duplicate != nullptr)
		Q.enqueue(duplicate);

	while (!Q.isEmpty()) {
		remove(Q.dequeue());
		duplicate = searchNode(node->right, node->value);
		if (duplicate != nullptr)
			Q.enqueue(duplicate);
		duplicate = searchNode(node->left, node->value);
		if (duplicate != nullptr)
			Q.enqueue(duplicate);
	}
	if (node->right != nullptr)
		deleteDuplicateNodes(node->right);
}
template <class T>
T SearchTree<T>::successor(T value) {
	typename Tree<T>::Node* node = searchNode(Tree<T>::root, value);
	typename Tree<T>::Node* succ = successor(node);
	return succ->value;
}