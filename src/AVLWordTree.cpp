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
    else if (value > root->getValue())
        root->setRightChild(insert(root->getRightChild(), value));

    root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                        heightOfAVLNode(root->getRightChild())) +
                    1);
    root = balance(root);

    return root;
}

AVLNode *AVLWordTree::balance(AVLNode *root)
{
    int balancedFactor = balanceFactor(root);

    if (balancedFactor > 1) // left heavy tree
    {
        if (balanceFactor(root->getLeftChild()) > 0)
        {
            root = rightRotation(root);
        }
        else
        {
            root->setLeftChild(leftRotation(root->getLeftChild()));
            root = rightRotation(root);
        }
    }
    else if (balancedFactor < -1) // right heavy tree
    {
        if (balanceFactor(root->getRightChild()) > 0)
        {
            root->setRightChild(rightRotation(root->getRightChild()));
            root = leftRotation(root);
        }
        else
        {
            root = leftRotation(root);
        }
    }
    return root;
}

AVLNode *AVLWordTree::leftRotation(AVLNode *root)
{
    AVLNode *newRoot = root->getRightChild();
    root->setRightChild(newRoot->getLeftChild());

    root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                        heightOfAVLNode(root->getRightChild())) +
                    1);
    newRoot->setLeftChild(root);

    newRoot->setHeight(max(heightOfAVLNode(newRoot->getLeftChild()),
                           heightOfAVLNode(newRoot->getRightChild())) +
                       1);
    return newRoot;
}

AVLNode *AVLWordTree::rightRotation(AVLNode *root)
{
    AVLNode *newRoot = root->getLeftChild();
    root->setLeftChild(newRoot->getRightChild());

    root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                        heightOfAVLNode(root->getRightChild())) +
                    1);
    newRoot->setRightChild(root);

    newRoot->setHeight(max(heightOfAVLNode(newRoot->getLeftChild()),
                           heightOfAVLNode(newRoot->getRightChild())) +
                       1);
    return newRoot;
}

int AVLWordTree::balanceFactor(AVLNode *root) const
{
    return root == nullptr
               ? 0
               : heightOfAVLNode(root->getLeftChild()) - heightOfAVLNode(root->getRightChild());
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

int AVLWordTree::heightOfAVLNode(AVLNode *node) const
{
    return node == nullptr ? -1 : node->getHeight();
}

bool AVLWordTree::isEmpty() const
{
    return root == nullptr ? true : false;
}
