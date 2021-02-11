#ifndef AVL_WORD_TREE_IG
#define AVL_WORD_TREE_IG

class AVLNode
{
public:
    AVLNode(int);

private:
    int value;
    AVLNode *rightChild;
    AVLNode *leftChild;
};

#endif