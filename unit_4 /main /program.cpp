  
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

// Insert a node into BST
void insert(Node* &root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }

    if (key < root->key)
        insert(root->left, key);
    else if (key > root->key)
        insert(root->right, key);
}

// Display BST using inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Delete a node having exactly one child
bool deleteOneChild(Node* &root, int key,
                    Node* parent = NULL) {
    if (root == NULL) {
        cout << "Key not found!" << endl;
        return false;
    }

    if (key < root->key)
        return deleteOneChild(root->left, key, root);

    if (key > root->key)
        return deleteOneChild(root->right, key, root);

    int children = (root->left != NULL) +
                   (root->right != NULL);

    if (children != 1) {
        cout << "Node does not have exactly one child."
             << endl;
        return false;
    }

    Node* temp = root;
    Node* child = (root->left != NULL)
                    ? root->left : root->right;

    cout << "Deleted node: " << key << endl;
    cout << "Child connected: " << child->key << endl;

    if (parent == NULL) {
        cout << "Root replaced by: "
             << child->key << endl;
    }
    else if (parent->left == root) {
        cout << "Parent " << parent->key
             << " left link updated to "
             << child->key << endl;
    }
    else {
        cout << "Parent " << parent->key
             << " right link updated to "
             << child->key << endl;
    }

    root = child;
    delete temp;

    return true;
}

int main() {
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(root, value);
    }

    cout << "Original BST (Inorder): ";
    inorder(root);

    cout << "\nEnter key to delete: ";
    cin >> key;

    deleteOneChild(root, key);

    cout << "Updated BST (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
