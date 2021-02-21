# AVLWordTree

In computer science, an AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.

## Operations
Operation | Average | Worst Case
--- | --- | ---
Insert | O(log n) | O(log n)
Delete | O(log n) | O(log n)
Search | O(log n) | O(log n)
Search By Filters | O(n) | O(n)
Traversal | O(n) | O(n)
Clear | O(n) | O(n)

## Self balancing 
Whenever the balance factor of a node is not -1 or 0 or 1, the AVL tree balances itself.The balance factor of each node is calculated as follows:
```
height of left child - height of right child
```

Self balancing is done in the following ways:
- Left rotation
- Right rotation
- Right-Left rotation
- Left-Right rotation

![result](https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif)
