## Problem statement

Write a C++ program to delete a node having exactly one child from a Binary Search Tree (BST) and display the updated tree. The program should display the parent and child links affected by deletion, handle deletion of the root node having one child, and display an appropriate message if the requested key is not found in the BST.
## Approach
1. Create the BST: Insert the given values into a Binary Search Tree according to BST rules.

2. Search for the node: Search for the node to be deleted and identify its parent.

3. Check the node: Verify whether the node has exactly one child. If it has zero or two children, display an appropriate message.

4. Update the links: Connect the parent directly to the deleted node’s only child and remove the node from the tree.

5. Handle root deletion: If the node to be deleted is the root, make its only child the new root.

6. Handle missing key: If the requested key is not found, display “Key not found!” without changing the tree.

7. Display the result: Display the affected parent-child links and the updated BST.
## Complexity analysis
The time complexity of this program is O(h) for deleting a node in the Binary Search Tree, where 
h
h is the height of the tree, because the algorithm traverses a single path from the root to the requested key. If the node is found and has exactly one child, the deletion and reconnection of the child take 
O
(
1
)
O(1) additional time. The time complexity is O(log n) for a balanced BST and O(n) for a skewed BST, where 
n
n is the number of nodes. The auxiliary space complexity is O(h) because the recursive deletion function uses stack space proportional to the height of the tree. Therefore, the space complexity is O(log n) for a balanced BST and O(n) in the worst case.
## Conclusion
The program successfully deletes a node having exactly one child from a Binary Search Tree and displays the updated tree. It also displays the affected parent–child links, handles deletion of the root node by assigning its child as the new root, and reports when the requested key is absent. Thus, the program demonstrates BST deletion and basic pointer handling in C++.
