## Section 2: Review Questions and Exercises
### 1. The class Stuff has both a copy constructor and an overloaded = operator. Assume that blob and clump are both instances of the Stuff class. For each of the statements, indicate whether the copy constructor or the overloaded = operator will be called.

#### Stuff blob = clump;
Copy Constructor.

#### clump = blob;
Overloaded = operator.

#### showValues(blob);
Copy Constructor

### 2. Describe the difference between making a class a member of another class (object composition) and making a class a friend of another class.

Object Composition involves making an instance of one class a member variable of another class.

Friend Class is a mechanism that grants one class full access to the private and protected members of another class.

### 3. Explain why a class's copy constructor is called when an object of that class is passed by value into a function.

When an object is passed by value, the function creates a local copy of that object to work with. Since a new object is being created and initialized with the data from the original object, the compiler must call the copy constructor to ensure the data is duplicated correctly.

### 4. Assume a class named Bird exists. Write the header for a member function that overloads the = operator for that class.

```cpp
Bird& operator=(const Bird &right);
 ```

### 5. Assume a class named Dollar exists. Write the headers for member functions that overload the prefix and postfix ++ operators for that class.

```cpp
// Prefix ++
Dollar& operator++();

// Postfix ++
Dollar operator++(int);
 ```