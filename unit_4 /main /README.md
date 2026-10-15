## Problem Statement
BST Deletion of a Node with One Child:- Write a C++ program to delete a node having exactly one child from a BST and display the updated tree.
## Approach
In a Binary Search Tree (BST), the left child contains smaller values and the right child contains larger values.

To delete a node having exactly one child, follow these steps:

1. Search for the node to be deleted.

2. Check whether the node has only one child (either left or right).

3. Replace the node with its only child.

4. Delete the original node and display the updated BST using inorder traversal.
 ## Complexity analysis
The time complexity of deleting a node with exactly one child in a Binary Search Tree (BST) is O(h), where 
h
h is the height of the tree. The algorithm searches for the specified node by traversing the tree from the root, requiring at most 
O
(
h
)
O(h) time, and then replaces the node with its only child in 
O
(
1
)
O(1) time. In a balanced BST, the height is 
O
(
log
⁡
n
)
O(logn), so the time complexity is 
O
(
log
⁡
n
)
O(logn), whereas in a skewed BST, the height can be 
O
(
n
)
O(n), resulting in linear time complexity. The auxiliary space complexity is O(h) because the recursive deletion function uses the call stack, which is 
O
(
log
⁡
n
)
O(logn) for a balanced BST and 
O
(
n
)
O(n) for a skewed BST.
## Conclusion
The C++ program successfully deletes a node having exactly one child from a Binary Search Tree. It updates the parent-child links correctly, handles deletion of the root node, and checks whether the requested key exists. The updated BST is displayed using inorder traversal, which helps verify that the Binary Search Tree property is maintained.
