#ifndef AVL_WORD_TREE_IG
#define AVL_WORD_TREE_IG

#include <string>
#include <vector>

class AVLNode
{
public:
    explicit AVLNode(const std::string &);
    void setValue(const std::string &);
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
    bool search(const std::string &) const;
    void remove(const std::string &);
    std::vector<std::string> start_with(const char &) const;
    std::vector<std::string> end_with(const char &) const;
    std::vector<std::string> contains(const std::string &) const;
    void traversePreOrder() const;
    void traverseInOrder() const;
    void traversePostOrder() const;
    void traverseLevelOrder() const;
    bool isEmpty() const;
    ~AVLWordTree();

private:
    AVLNode *root = nullptr;
    AVLNode *insert(AVLNode *, std::string);
    AVLNode *remove(AVLNode *, const std::string &);
    AVLNode *minNode(AVLNode *);
    int compareTwoString(const std::string &, const std::string &) const;
    void traversePreOrder(AVLNode *) const;
    void traverseInOrder(AVLNode *) const;
    void traversePostOrder(AVLNode *) const;
    int heightOfAVLNode(AVLNode *) const;
    int balanceFactor(AVLNode *) const;
    AVLNode *balance(AVLNode *);
    AVLNode *rightRotation(AVLNode *);
    AVLNode *leftRotation(AVLNode *);
};

#endif