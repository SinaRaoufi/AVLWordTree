#include "AVLWordTree.hpp"
#include <iostream>
#include <queue>

using namespace std;

// AVLNode class constructor
AVLNode::AVLNode(string value)
{
    setValue(value);
    height = 0;
    rightChild = nullptr;
    leftChild = nullptr;
}

// setter member function for the value field
void AVLNode::setValue(const string &value)
{
    this->value = value;
}

// getter member function for the value field
string AVLNode::getValue() const
{
    return value;
}

// setter member function for the height field
void AVLNode::setHeight(int height)
{
    this->height = height;
}

// getter member function for the height field
int AVLNode::getHeight() const
{
    return height;
}

// getter member function for the rightChild field
AVLNode *AVLNode::getRightChild() const
{
    return rightChild;
}

// getter member function for the leftChild field
AVLNode *AVLNode::getLeftChild() const
{
    return leftChild;
}

// setter member function for the rightChild field
void AVLNode::setRightChild(AVLNode *rightChild)
{
    this->rightChild = rightChild;
}

// setter member function for the leftChild field
void AVLNode::setLeftChild(AVLNode *leftChild)
{
    this->leftChild = leftChild;
}

// utility member function: compare two string
int AVLWordTree::compareTwoString(const std::string &str1, const std::string &str2) const
{
    int result = str1.compare(str2);
    if (result == 0) // 0 if str1 and str2 are equal
        return 0;
    else if (result > 0) // 1 if str1 is greater than str2
        return 1;
    else // -1 if str1 is lower than str2
        return -1;
}

// insert new node to AVL tree
void AVLWordTree::insert(string value)
{
    root = insert(root, value);
}

// utility member function: insert new node to AVL tree
AVLNode *AVLWordTree::insert(AVLNode *root, string value)
{
    // base condition
    if (root == nullptr)
        return new AVLNode(value);
    // find the suitable place to insert new node
    if (compareTwoString(value, root->getValue()) == -1)
        root->setLeftChild(insert(root->getLeftChild(), value));
    else if (compareTwoString(value, root->getValue()) == 1)
        root->setRightChild(insert(root->getRightChild(), value));

    // update height of visited nodes
    root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                        heightOfAVLNode(root->getRightChild())) +
                    1);
    // balance visited nodes if they are unbalanced
    root = balance(root);

    return root;
}

// utility member function: balance the given node
AVLNode *AVLWordTree::balance(AVLNode *root)
{
    // calculate balance factor for the given node
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

// utility member function: rotate the given node to left (left rotation)
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

// utility member function: rotate the given node to right (right rotation)
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

// utility member function: calculate balance factor of the given node
int AVLWordTree::balanceFactor(AVLNode *root) const
{
    return root == nullptr
               ? 0
               : heightOfAVLNode(root->getLeftChild()) - heightOfAVLNode(root->getRightChild());
}

// traverse tree with Pre-Order traversal method
void AVLWordTree::traversePreOrder() const
{
    traversePreOrder(root);
    cout << endl;
}

// utility member function: traverse tree with Pre-Order traversal method
void AVLWordTree::traversePreOrder(AVLNode *root) const
{
    // root left right
    if (root == nullptr)
        return;
    cout << root->getValue() << ' ';
    traversePreOrder(root->getLeftChild());
    traversePreOrder(root->getRightChild());
}

// traverse tree with In-Order traversal method
void AVLWordTree::traverseInOrder() const
{
    traverseInOrder(root);
    cout << endl;
}

// utility member function: traverse tree with In-Order traversal method
void AVLWordTree::traverseInOrder(AVLNode *root) const
{
    // left root right
    if (root == nullptr)
        return;
    traverseInOrder(root->getLeftChild());
    cout << root->getValue() << ' ';
    traverseInOrder(root->getRightChild());
}

// traverse tree with Post-Order traversal method
void AVLWordTree::traversePostOrder() const
{
    traversePostOrder(root);
    cout << endl;
}

// utility member function: traverse tree with Post-Order traversal method
void AVLWordTree::traversePostOrder(AVLNode *root) const
{
    // left right root
    if (root == nullptr)
        return;
    traversePostOrder(root->getLeftChild());
    traversePostOrder(root->getRightChild());
    cout << root->getValue() << ' ';
}

// traverse tree with Level-Order traversal method
void AVLWordTree::traverseLevelOrder() const
{
    queue<AVLNode *> values;
    values.push(root);
    while (!values.empty())
    {
        // push right child and left child of desired node if they aren't nullptr
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        cout << values.front()->getValue() << ' ';
        values.pop();
    }
    cout << endl;
}

// utility member function: traverse tree with Level-Order traversal method
int AVLWordTree::heightOfAVLNode(AVLNode *node) const
{
    return node == nullptr ? -1 : node->getHeight();
}

// check if AVL tree is empty or not
bool AVLWordTree::isEmpty() const
{
    return root == nullptr ? true : false;
}

// search the given value in AVL tree
bool AVLWordTree::search(const string &value) const
{
    auto current = root;
    while (current != nullptr)
    {
        // find the desired node
        if (compareTwoString(value, current->getValue()) == -1)
            current = current->getLeftChild();
        else if (compareTwoString(value, current->getValue()) == 1)
            current = current->getRightChild();
        else
            return true; // return true if a node with the desired value found
    }
    return false; // return false if a node with the desired value not found
}

// return a vector of string consist of all values that started with the desired character
vector<string> AVLWordTree::start_with(const char &character) const
{
    vector<string> temp;
    queue<AVLNode *> values;

    values.push(root);
    while (!values.empty())
    {
        // push right child and left child of desired node if they aren't nullptr
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        // check if a node started with the given character
        if (values.front()->getValue().front() == character)
            temp.push_back(values.front()->getValue());

        values.pop();
    }
    return temp;
}

// return a vector of string consist of all values that ended in the desired character
vector<string> AVLWordTree::end_with(const char &character) const
{
    vector<string> temp;
    queue<AVLNode *> values;

    values.push(root);
    while (!values.empty())
    {
        // push right child and left child of desired node if they aren't nullptr
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        // check if a node ended with the given character
        if (values.front()->getValue()[values.front()->getValue().size() - 1] == character)
            temp.push_back(values.front()->getValue());

        values.pop();
    }
    return temp;
}

// return a vector of string consist of the given substring
vector<string> AVLWordTree::contains(const string &subString) const
{
    vector<string> temp;
    queue<AVLNode *> values;

    values.push(root);
    while (!values.empty())
    {
        // push right child and left child of desired node if they aren't nullptr
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        // check if a node contains the given substring
        if (values.front()->getValue().find(subString) != string::npos)
            temp.push_back(values.front()->getValue());

        values.pop();
    }
    return temp;
}

// AVLWordTree class destructor
AVLWordTree::~AVLWordTree()
{
    queue<AVLNode *> values;
    values.push(root);
    while (!values.empty())
    {
        // push right child and left child of desired node if they aren't nullptr
        if (values.front()->getLeftChild() != nullptr)
            values.push(values.front()->getLeftChild());
        if (values.front()->getRightChild() != nullptr)
            values.push(values.front()->getRightChild());
        delete values.front();
        values.pop();
    }
}

// utility member function: find the left most node of the given subtree
AVLNode *AVLWordTree::minNode(AVLNode *root)
{
    auto current = root;
    auto leftMostNode = root;
    while (current != nullptr)
    {
        leftMostNode = current;
        current = current->getLeftChild();
    }
    return leftMostNode;
}

// utility member function: delete a node from the desired AVL tree
AVLNode *AVLWordTree::remove(AVLNode *root, const string &value)
{
    // base condition
    if (root == nullptr)
        return root;

    // find the desired node to delete
    if (compareTwoString(value, root->getValue()) == -1)
    {
        root->setLeftChild(remove(root->getLeftChild(), value));
        // update height of visited nodes
        root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                            heightOfAVLNode(root->getRightChild())) +
                        1);
        // balance visited nodes if they are unbalanced
        root = balance(root);
    }
    else if (compareTwoString(value, root->getValue()) == 1)
    {
        root->setRightChild(remove(root->getRightChild(), value));
        // update height of visited nodes
        root->setHeight(max(heightOfAVLNode(root->getLeftChild()),
                            heightOfAVLNode(root->getRightChild())) +
                        1);
        // balance visited nodes if they are unbalanced
        root = balance(root);
    }
    else // the desired node founded
    {
        if (root->getLeftChild() == nullptr)
        {
            auto temp = root->getRightChild();
            delete root;
            return temp;
        }
        else if (root->getRightChild() == nullptr)
        {
            auto temp = root->getLeftChild();
            delete root;
            return temp;
        }
        else
        {
            // find minimum value of right subtree
            AVLNode *min = minNode(root->getRightChild());
            // replace desired node with minimum value of right subtree
            root->setValue(min->getValue());
            // delete duplicated node
            root->setRightChild(remove(root->getRightChild(), min->getValue()));
        }
    }
    return root;
}

// delete a node from the AVL tree
void AVLWordTree::remove(const string &value)
{
    root = remove(root, value);
}