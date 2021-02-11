#ifndef AVL_WORD_TREE_IG
#define AVL_WORD_TREE_IG

class AVLNode
{
public:
    AVLNode(int);
    int getValue() const;
    void setRightChild(AVLNode *);
    void setLeftChild(AVLNode *);
    AVLNode *getRightChild() const;
    AVLNode *getLeftChild() const;

private:
    int value;
    AVLNode *rightChild;
    AVLNode *leftChild;
};

class AVLWordTree
{
public:
    void insert(int);
    void traverseInOrder() const;

private:
    AVLNode *root = nullptr;
    AVLNode *insert(AVLNode *, int);
    void traverseInOrder(AVLNode *) const;
};

#endif