## Section 2: Review Questions and Exercises

### 1. Explain the difference between static binding and dynamic binding.

In static binding, the compiler matches the function call with the correct function definition before the program even runs. In dynamic binding, the program waits until runtime to determine which function to actually execute.

```cpp
class Base {
    public:
        virtual void function() {}
};

class Derived : public Base {
    public:
        void function() override {}
};
```

### 2. Are virtual functions statically bound or dynamically bound?

Dynamically bound

### 3. How can you tell from looking at a class declaration that a virtual member function is pure?

```cpp
virtual void function() = 0;
```

### 4. What makes an abstract class different from other classes?

We cannot make a object from an abstract class directly.

### 5. Find all errors in the following fragment of code.

```cpp
class MyClass
{
    public:
        virtual void myFun() = 0;
        { cout << "Hello"; }
};
```

```cpp
class MyClass
{
    public:
        virtual void myFun() = 0;
};
```