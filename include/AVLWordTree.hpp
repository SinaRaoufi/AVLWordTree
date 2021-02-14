#ifndef AVL_WORD_TREE_IG
#define AVL_WORD_TREE_IG

class AVLNode
{
public:
    AVLNode(int);
    int getValue() const;
    void setHeight(int);
    int getHeight() const;
    void setRightChild(AVLNode *);
    void setLeftChild(AVLNode *);
    AVLNode *getRightChild() const;
    AVLNode *getLeftChild() const;

private:
    int value;
    int height;
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
    int heightOfAVLNode(AVLNode *) const;
    int balanceFactor(AVLNode *) const;
    AVLNode *balance(AVLNode *);
    AVLNode *rightRotation(AVLNode *);
    AVLNode *leftRotation(AVLNode *);
};

#endif