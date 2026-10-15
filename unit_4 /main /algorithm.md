## Algorithm
1. Start the program.

2. Create a Binary Search Tree by inserting the given values.

3. Display the original BST using inorder traversal.

4. Enter the key of the node to be deleted.

5. Search for the node and its parent in the BST.

6. If the key is not found, display "Key not found!".

7. If the node has no children or two children, display a message that it does not have exactly one child.

8. If the node has exactly one child:

- Connect its parent directly to its child.

- If the node is the root, make its child the new root.

- Delete the selected node.

9. Display the updated BST using inorder traversal.

10. Stop the program.
