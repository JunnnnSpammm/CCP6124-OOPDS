#include <iostream>
#include <string>

using namespace std;

class IntBinaryTree
{
    private:
        struct TreeNode
        {
            int value;
            TreeNode* left;
            TreeNode* right;
            TreeNode(int value1,
                     TreeNode* left1 = nullptr,
                     TreeNode* right1 = nullptr)
            {
                value = value1;
                left = left1;
                right = right1;
            }
        };

        TreeNode* root;

        // helper member functions of private interface
        void insert(TreeNode*& tree, int num);
        void destroySubtree(TreeNode* tree);
        void remove(TreeNode*& tree, int num);
        void makeDeletion(TreeNode*& tree);

        void displayInOrder(TreeNode* tree) const;
        void displayPreOrder(TreeNode* tree) const;
        void displayPostOrder(TreeNode* tree) const;
        
        // Private helper for counting nodes recursively
        int countNodes(TreeNode* tree) const;

    public:
    // these member functions are the public interface
    IntBinaryTree()
    {
        root = nullptr;
    }

    ~IntBinaryTree()
    {
        destroySubtree(root);
    }

    void insert(int num)
    {
        insert(root, num);
    }

    bool search(int num) const;

    void remove(int num)
    {
        remove(root, num);
    }

    void showInOrder() const
    {
        displayInOrder(root);
    }

    void showPreOrder() const
    {
        displayPreOrder(root);
    }

    void showPostOrder() const
    {
        displayPostOrder(root);
    }

    // Public member function to get the size of the tree
    int size() const
    {
        return countNodes(root);
    }
};

void IntBinaryTree::insert(TreeNode*& tree, int num)
{
    // If the tree is empty, make a new node and
    // make it the root of the tree.
    if (!tree)
    {
        tree = new TreeNode(num);
        return;
    }

    // If num is already in tree: return.
    if (tree->value == num)
        return;

    // The tree is not empty:
    // recursive insert() the new node into the
    // left or right subtree.
    if (num < tree->value)
        insert(tree->left, num);
    else
        insert(tree->right, num);
}

void IntBinaryTree::destroySubtree(TreeNode* tree)
{
    if (!tree) return;

    // recursive destroySubtree()
    destroySubtree(tree->left);
    destroySubtree(tree->right);

    // Delete the node at the root.
    delete tree;
}

bool IntBinaryTree::search(int num) const
{
    TreeNode* tree = root;

    while (tree)
    {
        if (tree->value == num)
            return true;
        else if (num < tree->value)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return false;
}

void IntBinaryTree::remove(TreeNode*& tree, int num)
{
    if (tree == nullptr) return;

    if (num < tree->value)
        remove(tree->left, num);
    else if (num > tree->value)
        remove(tree->right, num);
    else
        // We have found the node to delete.
        makeDeletion(tree);
}

void IntBinaryTree::makeDeletion(TreeNode*& tree)
{
    // Used to hold node that will be deleted.
    TreeNode* nodeToDelete = tree;

    // Used to locate the point where the
    // left subtree is attached.
    TreeNode* attachPoint;

    if (tree->right == nullptr)
    {
        tree = tree->left;
    }
    else if (tree->left == nullptr)
    {
        tree = tree->right;
    }
    else
    {
        // Move to right subtree.
        attachPoint = tree->right;

        // Locate the smallest node in the right subtree
        // by moving as far to the left as possible.
        while (attachPoint->left != nullptr)
            attachPoint = attachPoint->left;

        // Attach the left subtree of the original tree
        // as the left subtree of the smallest node
        // in the right subtree.
        attachPoint->left = tree->left;

        tree = tree->right;
    }

    // Delete the tree node
    delete nodeToDelete;
}

void IntBinaryTree::displayInOrder(TreeNode* tree) const
{
    if (tree)
    {
        displayInOrder(tree->left);
        cout << tree->value << " ";
        displayInOrder(tree->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode* tree) const
{
    if (tree)
    {
        cout << tree->value << " ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode* tree) const
{
    if (tree)
    {
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        cout << tree->value << " ";
    }
}

// Recursive helper function to count nodes
int IntBinaryTree::countNodes(TreeNode* tree) const
{
    if (tree == nullptr)
        return 0;
    
    // Total size = 1 (current node) + size of left subtree + size of right subtree
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int main()
{
    IntBinaryTree tree;

    // Test size on empty tree
    cout << "Initial tree size: " << tree.size() << "\n\n";

    cout << "Inserting the numbers 5 8 3 12 9\n";
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    tree.insert(12);
    tree.insert(9);

    // Verify size after insertion
    cout << "Tree size after insertions: " << tree.size() << "\n\n";

    if (tree.search(3))
        cout << "3 is found in the tree\n";
    else
        cout << "3 was not found in the tree\n";
    
    cout << "Inorder traversal: ";
    tree.showInOrder();
    cout << endl;

    cout << "Deleting 8\n";
    tree.remove(8);
    cout << "Tree size after deleting 8: " << tree.size() << "\n";

    cout << "Deleting 12\n";
    tree.remove(12);
    cout << "Tree size after deleting 12: " << tree.size() << "\n\n";

    cout << "Inorder traversal again: ";
    tree.showInOrder();
    cout << endl;

    return 0;
}

/*
Sample Output: 

Initial tree size: 0

Inserting the numbers 5 8 3 12 9
Tree size after insertions: 5

3 is found in the tree
Inorder traversal: 3 5 8 9 12 
Deleting 8
Tree size after deleting 8: 4
Deleting 12
Tree size after deleting 12: 3

Inorder traversal again: 3 5 9 
*/