//
//  BinaryTree.hpp
//  Arboles-Balanceados
//
//  Created by Alex Gutz on 8/31/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
class TreeNode {
private:
	T data;
	TreeNode * left = nullptr;
	TreeNode * right = nullptr;
	int height = 1;
public:
	TreeNode() {}
	TreeNode(T _data) { data = _data; }
	T getData() { return data; }
	void setData(T _data) { data = _data; }
	TreeNode * getLeft() { return left; }
	void setLeft(TreeNode * _left) { left = _left; }
	TreeNode * getRight() { return right; }
	void setRight(TreeNode * _right) { right = _right; }
	int getHeight() { return height; }
	void setHeight(int _height) { height = _height; }

	template <class S>
	friend ostream & operator<< (ostream & stream, const TreeNode<S> & node);
};

template <class T>
ostream & operator<< (ostream & stream, const TreeNode<T> & node) {
	stream << node.data;
	return stream;
}

#define INCREMENT 5
//Binary Tree
template <class T>
class BinaryTree {
    protected:
        TreeNode<T> * root = nullptr;

        void clear(TreeNode<T> * _root);
        TreeNode<T> * getMin(TreeNode<T> * _root);
        int countLeaves(TreeNode<T> * _root);
        void printInOrder(TreeNode<T> * _root);
        void printPostOrder(TreeNode<T> * _root);
        void printTree(TreeNode<T> * _root, int indent, char branch);
        
    public:
        BinaryTree () {}
        BinaryTree (TreeNode<T> * node) { root = node; }
        ~BinaryTree () { clear(); }
        void clear();
		//Root
        TreeNode<T> * getRoot() { return root; }
        void setRoot(TreeNode<T> * _root) { root = _root; }
        //Auxiliary Methods methods
        TreeNode<T> * getMin() { return getMin(root); }
        int countLeaves() { return countLeaves(root); }

		//Print
        void printInOrder() { printInOrder(root); }
        void printPostOrder() { printPostOrder(root); }
        void printTree() { printTree(root, INCREMENT, '-'); }
};

template <class T>//Delete subtree
void BinaryTree<T>::clear (TreeNode<T> * root){
    if (root){
        clear(root->getLeft());
        clear(root->getRight());
        delete root;
    }
}

template <class T>//Delete Entire Tree
void BinaryTree<T>::clear() {
	clear(root);
	root = nullptr;
}

template <class T>
TreeNode<T> * BinaryTree<T>::getMin(TreeNode<T> * root){
    if (root == nullptr)
        return nullptr;
    if (!root->getLeft())
        return root;
    return getMin(root->getLeft());
}

template <class T>
int BinaryTree<T>::countLeaves(TreeNode<T> * root){
    if (root == nullptr)//Test Empty
        return 0;
    else if (!root->getLeft() && !root->getRight())//No child = leaf
        return 1;
    else
        return countLeaves(root->getLeft()) + countLeaves(root->getRight());
}

template <class T>
void BinaryTree<T>::printInOrder(TreeNode<T> * root){
    if (root != nullptr){
        printInOrder(root->getLeft());
        cout << " " << root->getData() << " ";
        printInOrder(root->getRight());
    }
}

template <class T>
void BinaryTree<T>::printPostOrder(TreeNode<T> * root){
    if (root != nullptr){
        printPostOrder(root->getLeft());
        printPostOrder(root->getRight());
        cout << " " << root->getData() << " ";
    }
}

// Private method to print the tree in a semi graphical form in the terminal
// The tree will appear rotated 90 degrees counter clock-wise
template <class T>
void BinaryTree<T>::printTree(TreeNode<T> * root, int indent, char branch){
    // Print only if the tree is not empty
    if (root != nullptr) {
        // Print right branch first (at the top)
        printTree(root->getRight(), indent+INCREMENT, '/');
        // Print the root node of this subtree
        cout << setw(indent) << branch << "- " << root->getData() << endl;
        // Print the left branch
        printTree(root->getLeft(), indent+INCREMENT, '\\');
    }
}

