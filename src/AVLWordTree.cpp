#include "AVLWordTree.hpp"
#include <iostream>
#include <queue>

using namespace std;

AVLNode::AVLNode(string value)
{
    this->value = value;
    height = 0;
    rightChild = nullptr;
    leftChild = nullptr;
}

string AVLNode::getValue() const
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

int AVLWordTree::compareTwoString(std::string str1, std::string str2) const
{
    int result = str1.compare(str2);
    if (result == 0) // 0 if str1 and str2 are equal
        return 0;
    else if (result > 0) // 1 if str1 is greater than str2
        return 1;
    else // -1 if str1 is lower than str2
        return -1;
}

void AVLWordTree::insert(string value)
{
    root = insert(root, value);
}

AVLNode *AVLWordTree::insert(AVLNode *root, string value)
{
    if (root == nullptr)
        return new AVLNode(value);

    if (compareTwoString(value, root->getValue()) == -1)
        root->setLeftChild(insert(root->getLeftChild(), value));
    else if (compareTwoString(value, root->getValue()) == 1)
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

void AVLWordTree::traversePreOrder() const
{
    traversePreOrder(root);
    cout << endl;
}

void AVLWordTree::traversePreOrder(AVLNode *root) const
{
    // root left right
    if (root == nullptr)
        return;
    cout << root->getValue() << ' ';
    traversePreOrder(root->getLeftChild());
    traversePreOrder(root->getRightChild());
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

void AVLWordTree::traversePostOrder() const
{
    traversePostOrder(root);
    cout << endl;
}

void AVLWordTree::traversePostOrder(AVLNode *root) const
{
    // left right root
    if (root == nullptr)
        return;
    traversePostOrder(root->getLeftChild());
    traversePostOrder(root->getRightChild());
    cout << root->getValue() << ' ';
}

void AVLWordTree::traverseLevelOrder() const
{
    traverseLevelOrder(root);
    cout << endl;
}

void AVLWordTree::traverseLevelOrder(AVLNode *root) const
{
    queue<AVLNode *> values;
    values.push(root);
    while (!values.empty())
    {
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        cout << values.front()->getValue() << ' ';
        values.pop();
    }
}

int AVLWordTree::heightOfAVLNode(AVLNode *node) const
{
    return node == nullptr ? -1 : node->getHeight();
}

bool AVLWordTree::isEmpty() const
{
    return root == nullptr ? true : false;
}

bool AVLWordTree::search(string value) const
{
    auto current = root;
    while (current != nullptr)
    {
        if (compareTwoString(value, current->getValue()) == -1)
            current = current->getLeftChild();
        else if (compareTwoString(value, current->getValue()) == 1)
            current = current->getRightChild();
        else
            return true;
    }
    return false;
}

// AVLWordTree::~AVLWordTree()
// {
//     // left right root
//     if (root == nullptr)
//         return;
//     traversePostOrder(root->getLeftChild());
//     traversePostOrder(root->getRightChild());
//     delete root;
// }