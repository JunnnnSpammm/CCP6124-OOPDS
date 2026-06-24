## Section 2: Review Questions and Exercises

### 1. In what ways is a binary tree similar to a linked list?

Both are dynamic data structures built from individual nodes. Each node contains a value and pointers to other nodes. Both structures grow and shrink dynamically at runtime. Memory is allocated as new elements are added. Accessing elements requires traversing pointers from a starting point (the head in a linked list, or the root in a tree). You cannot access elements directly by an index like in an array.

### 2. A ternary tree is like a binary tree, except each node in a ternary tree may have three children: a left child, a middle child, and a right child. Write an analog of the TreeNode declaration that can be used to represent the nodes of a ternary tree.

```cpp
struct TreeNode 
{
    int value;
    TreeNode* left;
    TreeNode* middle;
    TreeNode* right;
};
```

### 3. Imagine a tree in which each node can have up to a hundred children. Write an analog of the TreeNode declaration that can be used to represent the nodes of such a tree. A declaration such as

```cpp
struct TreeNode
{
    int value;
    TreeNode* child1;
    TreeNode* child2;
    TreeNode* child3;
    . . .
    . . .
    . . .
};
```
that simply lists all the pointers to the hundred children is not acceptable.

```cpp
struct TreeNode 
{
    int value;
    TreeNode* children[100]; 
};
```

