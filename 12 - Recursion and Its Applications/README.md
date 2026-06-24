## Section 2: Review Questions and Exercises

### 1. Which repetition approach is less efficient; a loop or a recursive function? Why?

Recursive function is less efficient than a loop.

Every time a recursive function calls itself, the operating system must allocate memory on the call stack to store the function's state while a loop stays within the same stack frame, simply updating the values of variables in place.

### 2. When should you choose a recursive algorithm over an iterative algorithm?

- When working with inherently hierarchical data structures because traversing a tree or graph is straightforward with recursion.
- When writing algorithms that break a large problem down into identical smaller sub-problems naturally fit the recursive mold such as sorting or searching
