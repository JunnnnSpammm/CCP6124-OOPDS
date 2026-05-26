## Section 2: Review Questions and Exercises

### Each of the following declarations or code segments has errors. Locate and explain the errors.

### 1. 
```cpp
catch
{
    quotient = divide(num1, num2);
    cout << "The quotient is " << quotient << endl;
}
try (string exceptionString)
{
    cout << exceptionString;
}
```

Try and catch is swapped. Catch should be below try.

### 2. 
```cpp
try
{
    quotient = divide(num1, num2);
}
cout << "The quotient is " << quotient << endl;
catch (string exceptionString)
{
    cout << exceptionString;
}
```

cout is in between try and catch block. It should be inside the try block.

### 3. 
```cpp
template <class T>
T square(T number) {
    return T * T;
}
```

T is a type. It should be number * number

### 4. 
```cpp
template <class T>
int square(int number) {
    return number*number;
}
```

Template function but T is not used. We can swap int to T.

### 5. 
```cpp
template <class T1, class T2>
T1 sum(T1 x, T1 y) {
    return x + y;
}
```
T2 not used. We can declare y as T2 instead of T1