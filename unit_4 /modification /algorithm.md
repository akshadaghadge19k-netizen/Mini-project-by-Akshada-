## Algorithm

1. Start the program.

2. Create a Binary Search Tree by inserting the given values.

3. Read the key of the node to be deleted.

4. Search for the node and its parent in the BST.

5. If the key is not found, display “Key not found!” and stop the deletion operation.

6. Check the number of children of the node:

- If it has zero or two children, display a message that it is not a one-child node.

- If it has exactly one child, identify that child.

7. If the node is the root, make its child the new root.

8. Otherwise, update the appropriate link of the parent to point to the child.

9. Display the affected parent–child links.

10. Delete the node and display the updated BST using inorder traversal.

11. Stop the program
