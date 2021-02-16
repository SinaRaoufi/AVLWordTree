#ifndef AVL_WORD_TREE_IG
#define AVL_WORD_TREE_IG

#include <string>

class AVLNode
{
public:
    AVLNode(std::string);
    std::string getValue() const;
    void setHeight(int);
    int getHeight() const;
    void setRightChild(AVLNode *);
    void setLeftChild(AVLNode *);
    AVLNode *getRightChild() const;
    AVLNode *getLeftChild() const;

private:
    std::string value;
    int height;
    AVLNode *rightChild;
    AVLNode *leftChild;
};

class AVLWordTree
{
public:
    void insert(std::string);
    void traversePreOrder() const;
    void traverseInOrder() const;
    void traversePostOrder() const;
    void traverseLevelOrder() const;
    bool isEmpty() const;
    int compareTwoString(std::string, std::string) const;

private:
    AVLNode *root = nullptr;
    AVLNode *insert(AVLNode *, std::string);
    void traversePreOrder(AVLNode *) const;
    void traverseInOrder(AVLNode *) const;
    void traversePostOrder(AVLNode *) const;
    void traverseLevelOrder(AVLNode *) const;
    int heightOfAVLNode(AVLNode *) const;
    int balanceFactor(AVLNode *) const;
    AVLNode *balance(AVLNode *);
    AVLNode *rightRotation(AVLNode *);
    AVLNode *leftRotation(AVLNode *);
};

#endif