#include <iostream>
#include <iomanip>
#include "AVLWordTree.hpp"

using namespace std;

int main()
{
    AVLWordTree tree;
    // an empty tree
    cout << "Is tree empty? " << boolalpha << tree.isEmpty() << endl;

    tree.insert("fig");
    // fig

    cout << "Is tree empty? " << boolalpha << tree.isEmpty() << endl;

    tree.insert("apple");
    //     fig
    // apple

    tree.insert("banana");
    //     fig                  fig
    // apple      ===>      banana    ===>        banana
    //    banana         apple                apple     fig

    tree.insert("grape");
    //      banana
    //  apple    fig
    //             grape

    tree.insert("kiwi");
    //      banana                      banana
    //  apple    fig               apple      grape
    //             grape     ===>          fig    kiwi
    //                kiwi

    cout << "PreOrder traversal: ";
    tree.traversePreOrder();
    cout << "InOrder traversal: ";
    tree.traverseInOrder();
    cout << "PostOrder traversal: ";
    tree.traversePostOrder();
    cout << "LevelOrder traversal: ";
    tree.traverseLevelOrder();

    cout << "Is blueberry exist in the tree? " << boolalpha << tree.search("blueberry") << endl;
    cout << "Is apple exist in the tree? " << boolalpha << tree.search("apple") << endl;

    cout << "=============================" << endl;

    tree.remove("apple");
    //      banana                 banana                     grape
    // apple      grape     ===>       grape      ===>  banana    kiwi
    //         fig    kiwi          fig    kiwi             fig

    cout << "PreOrder traversal: ";
    tree.traversePreOrder();
    cout << "InOrder traversal: ";
    tree.traverseInOrder();
    cout << "PostOrder traversal: ";
    tree.traversePostOrder();
    cout << "LevelOrder traversal: ";
    tree.traverseLevelOrder();

    cout << "Is apple exist in the tree? " << boolalpha << tree.search("apple") << endl;

    tree.insert("lime");
    tree.insert("grapefruit");

    auto result = tree.end_with('e');
    for (auto &word : result)
        cout << word << ' ';
    cout << endl;

    result = tree.start_with('g');
    for (auto &word : result)
        cout << word << ' ';
    cout << endl;

    result = tree.contains("rui");
    for (auto &word : result)
        cout << word << ' ';
    cout << endl;

    return 0;
}