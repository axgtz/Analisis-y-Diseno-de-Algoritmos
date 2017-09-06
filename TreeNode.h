/*
Jesús Horacio Rojas Cortés A01020026
Tree node class
*/
#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
template <class T>
class TreeNode {
    private:
        T data;
        TreeNode * left = nullptr;
        TreeNode * right = nullptr;
        int height = 1;
    
    public: 
        TreeNode () {}
        TreeNode (T _data) { data = _data; }
        T getData () { return data; }
        void setData (T _data) { data = _data; }
        TreeNode * getLeft() { return left; }
        void setLeft(TreeNode * _left) { left = _left; }
        TreeNode * getRight() { return right; }
        void setRight(TreeNode * _right) { right = _right; }
        void setHeight(int _height) { height = _height; }
        int getHeight() { return height; }
        
        template <class S>
        friend std::ostream & operator<< (std::ostream & stream, const TreeNode<T> & node);
};

template <class T>
std::ostream & operator<< (std::ostream & stream, const TreeNode<T> & node)
{
    stream << node.data;
    return stream;
}

#endif