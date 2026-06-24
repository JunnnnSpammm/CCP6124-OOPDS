#include <iostream>
#include <vector>

using namespace std;

class BST {
private:
    struct Node {
        double data;
        Node* left;
        Node* right;

        Node(double val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function for recursive insertion
    Node* insertHelper(Node* node, double num) {
        if (node == nullptr) {
            return new Node(num);
        }

        if (num < node->data) {
            node->left = insertHelper(node->left, num);
        } else {
            node->right = insertHelper(node->right, num);
        }
        return node;
    }

    // Helper function for recursive search
    bool searchHelper(Node* node, double num) const {
        if (node == nullptr) {
            return false;
        }

        if (node->data == num) {
            return true;
        } else if (num < node->data) {
            return searchHelper(node->left, num);
        } else {
            return searchHelper(node->right, num);
        }
    }

    // Helper function for recursive inorder traversal
    void inorderHelper(Node* node, vector<double>& v) const {
        if (node == nullptr) {
            return;
        }

        inorderHelper(node->left, v);  // Visit left subtree
        v.push_back(node->data);       // Visit current node
        inorderHelper(node->right, v); // Visit right subtree
    }

    // Helper function to deallocate memory
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroyTree(root);
    }

    // Inserts a number into the BST
    void insert(double num) {
        root = insertHelper(root, num);
    }

    // Searches for a number in the BST
    bool search(double num) const {
        return searchHelper(root, num);
    }

    // Fills the vector with the inorder traversal of the tree
    void inorder(vector<double>& v) const {
        inorderHelper(root, v);
    }
};

int main() {
    BST tree;

    cout << "Inserting values: 5.5, 3.3, 8.8, 1.1, 4.4, 7.7, 9.9\n\n";
    tree.insert(5.5);
    tree.insert(3.3);
    tree.insert(8.8);
    tree.insert(1.1);
    tree.insert(4.4);
    tree.insert(7.7);
    tree.insert(9.9);

    vector<double> inorderList;
    tree.inorder(inorderList);

    cout << "Inorder Traversal (should be sorted):" << endl;
    for (double val : inorderList) {
        cout << val << " ";
    }
    cout << "\n\n";

    double searchTargets[] = {4.4, 6.6, 9.9, 0.0};

    cout << "Testing Search Function:" << endl;
    for (double target : searchTargets) {
        if (tree.search(target)) {
            cout << "Value " << target << " WAS found in the tree." << endl;
        } else {
            cout << "Value " << target << " was NOT found in the tree." << endl;
        }
    }

    return 0;
}

/*
Sample Output: 

Inserting values: 5.5, 3.3, 8.8, 1.1, 4.4, 7.7, 9.9

Inorder Traversal (should be sorted):
1.1 3.3 4.4 5.5 7.7 8.8 9.9 

Testing Search Function:
Value 4.4 WAS found in the tree.
Value 6.6 was NOT found in the tree.
Value 9.9 WAS found in the tree.
Value 0 was NOT found in the tree.
*/