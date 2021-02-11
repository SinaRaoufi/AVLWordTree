#include "AVLWordTree.hpp"
#include <iostream>

using namespace std;

AVLNode::AVLNode(int value)
{
    this->value = value;
    height = 0;
    rightChild = nullptr;
    leftChild = nullptr;
}

int AVLNode::getValue() const
{
    return value;
}

void AVLNode::setHeight(int height)
{
    this->height = height;
}

int AVLNode::getHeight() const
{
    return height;
}

AVLNode *AVLNode::getRightChild() const
{
    return rightChild;
}

AVLNode *AVLNode::getLeftChild() const
{
    return leftChild;
}

void AVLNode::setRightChild(AVLNode *rightChild)
{
    this->rightChild = rightChild;
}

void AVLNode::setLeftChild(AVLNode *leftChild)
{
    this->leftChild = leftChild;
}

void AVLWordTree::insert(int value)
{
    root = insert(root, value);
}

AVLNode *AVLWordTree::insert(AVLNode *root, int value)
{
    if (root == nullptr)
        return new AVLNode(value);

    if (value < root->getValue())
        root->setLeftChild(insert(root->getLeftChild(), value));
    else
        root->setRightChild(insert(root->getRightChild(), value));

    return root;
}

void AVLWordTree::traverseInOrder() const
{
    traverseInOrder(root);
    cout << endl;
}

void AVLWordTree::traverseInOrder(AVLNode *root) const
{
    // left root right
    if (root == nullptr)
        return;
    traverseInOrder(root->getLeftChild());
    cout << root->getValue() << ' ';
    traverseInOrder(root->getRightChild());
}
