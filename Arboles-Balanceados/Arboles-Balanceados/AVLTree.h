//
//  AVLTree.hpp
//  Arboles-Balanceados
//
//  Created by Alex Gutz on 8/31/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include "BinarySearchTree.h"
#include <algorithm>
template <class T>
class AVLTree : public BinarySearchTree<T> {
    private:
      TreeNode<T> * insert(TreeNode<T> * root, TreeNode<T> * new_node);//Overload insertion from BST
      //Balance Methods
      int getBalanceFactor(TreeNode<T> * root);
      void updateHeight(TreeNode<T> * root);
      TreeNode<T> * balance(TreeNode<T> * root);
      TreeNode<T> * rotateLeft(TreeNode<T> * root);
      TreeNode<T> * rotateRight(TreeNode<T> * root);
    public:
        AVLTree(){}
        AVLTree(TreeNode<T> * node){ this->root = node;}
        void insert(TreeNode<T> * new_node);//Overloaded method
};

template <class T>
void AVLTree<T>::updateHeight(TreeNode<T> * root){
  if(!root)//Not empty
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if (root->getLeft() != nullptr) {
    leftHeight = root->getLeft()->getHeight();
  }
  if (root->getRight() != nullptr) {
    rightHeight = root->getRight()->getHeight();
  }
  root->setHeight(max(leftHeight,rightHeight)+1);
}

template <class T>
int AVLTree<T>::getBalanceFactor(TreeNode<T> * root){
  if(!root)//not empty
    return;
  int leftHeight = 0;
  int rightHeight = 0;
  if (root->getLeft() != nullptr) {
    leftHeight = root->getLeft()->getHeight();
  }
  if (root->getRight() != nullptr) {
    rightHeight = root->getRight()->getHeight();
  }
  return leftHeight-rightHeight;
}


//+++ Funciones Principales +++

template <class T>
TreeNode<T> * AVLTree<T>::rotateRight(TreeNode<T> * root){
  TreeNode<T> * child = root->getLeft();
  root->setLeft(child->getRight());
  child->setRight(root);
  updateHeight(root);
  updateHeight(child);
  return child;
}

template <class T>
TreeNode<T> * AVLTree<T>::rotateLeft(TreeNode<T> * root){
  TreeNode<T> * child = root->getRight();
  root->setRight(child->getLeft());
  child->setLeft(root);
  updateHeight(root);
  updateHeight(child);
  return child;
}

template <class T>
TreeNode<T> * AVLTree<T>::balance(TreeNode<T> * root){
  updateHeight(root);
  int balance_factor = getBalanceFactor(root);
  if (balance_factor==2) {
    if (getBalanceFactor(root->getLeft()) < 0){//IzqDer
      root->setLeft(rotateLeft(root->getLeft()));
    }//IzqIzq
    root = rotateRight(root);
  }
  if (balance_factor==-2) {
    if (getBalanceFactor(root->getRight()) > 0){
      //DerIzq
      root->setRight(rotateRight(root->getRight()));
    }
    //DerDer
    root = rotateLeft(root);
  }
  return root;
}

template <class T>
TreeNode<T> * AVLTree<T>::insert(TreeNode<T> * root, TreeNode<T> * new_node){
  insert(root,new_node);
  balance(root);
}

template <class T>
void AVLTree<T>::insert(TreeNode<T> * new_node) {
	if (this->root == nullptr)
		this->root = new_node;
	else
		this->root = BinarySearchTree<T>::insert(this->root, new_node);
}

