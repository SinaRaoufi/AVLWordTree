#include <iostream>
#include "AVLWordTree.hpp"

using namespace std;

int main()
{
    AVLWordTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.traverseInOrder();
    return 0;
}