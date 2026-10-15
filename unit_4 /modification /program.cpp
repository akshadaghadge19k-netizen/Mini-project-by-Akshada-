#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Search for a node and its parent
Node* search(Node* root, int key, Node*& parent) {
    parent = NULL;

    while (root != NULL && root->key != key) {
        parent = root;

        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}

// Display the BST in inorder
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Delete a node having exactly one child
Node* deleteOneChild(Node* root, int key) {
    Node* parent = NULL;
    Node* node = search(root, key, parent);

    if (node == NULL) {
        cout << "Key not found!" << endl;
        return root;
    }

    // Check whether exactly one child exists
    if ((node->left == NULL && node->right == NULL) ||
        (node->left != NULL && node->right != NULL)) {
        cout << "Node does not have exactly one child."
             << endl;
        return root;
    }

    // Identify the only child
    Node* child = (node->left != NULL)
                    ? node->left : node->right;

    cout << "Parent: ";
    if (parent == NULL)
        cout << "None (node is root)" << endl;
    else
        cout << parent->key << endl;

    cout << "Child: " << child->key << endl;

    // If the node is the root
    if (parent == NULL) {
        cout << "Root updated: " << node->key
             << " -> " << child->key << endl;
        root = child;
    }
    else if (parent->left == node) {
        cout << "Parent " << parent->key
             << "'s left link: " << node->key
             << " -> " << child->key << endl;
        parent->left = child;
    }
    else {
        cout << "Parent " << parent->key
             << "'s right link: " << node->key
             << " -> " << child->key << endl;
        parent->right = child;
    }

    delete node;
    cout << "Node deleted successfully." << endl;

    return root;
}

int main() {
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    cout << "Enter key to delete: ";
    cin >> key;

    root = deleteOneChild(root, key);

    cout << "Updated BST (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
