## Section 2: Review Questions and Exercises

### 1. Using the ListNode structure introduced in the section 1, write a function
```cpp
void printFirst(ListNode* ptr)
```
that prints the value stored in the first node of a list passed to it as parameter. The function should print an error message and terminate the program if the list passed to it is empty.

```cpp
void printFirst(ListNode* ptr) {
    if (ptr == nullptr) {
        cout << "ERROR: Empty list!";
        throw;
    }
    
    cout << ptr->value;
}
```

### 2. Write a function
```cpp
void printSecond(ListNode* ptr)
```
that prints the value stored in the second node of a list passed to it as parameter. The function should print an error message and terminate the program if the list passed to it has less than two nodes.

```cpp
void printSecond(ListNode* ptr) {
    if (ptr == nullptr || ptr->next == nullptr) {
        cout << "ERROR: Empty list!";
        throw;
    }

    cout << ptr->next->value;
}
```

### 3. Write a recursive function
```cpp
double lastValue(ListNode* ptr)
```
that returns the value stored in the last node of a nonempty list passed to it as parameter. The function should print an error message and terminate the program if the list passed to it is empty.

```cpp
double lastValue(ListNode* ptr) {
    if (ptr == nullptr) {
        cout << "ERROR: Empty list!";
        throw;
    }

    // If last node
    if (ptr->next == nullptr) {
        return ptr->value;
    }

    return lastValue(ptr->next);
}
```

### 4. Write a function
```cpp
ListNode* removeFirst(ListNode* ptr)
```
that is passed a linked list as parameter and returns the tail of the list: That is, it removes the first node and returns what is left. The function should deallocate the storage of the removed node. The function returns nullptr if the list passed to it is empty.

```cpp
ListNode* removeFirst(ListNode* ptr) {
    if (ptr == nullptr) return nullptr;

    ListNode* newNode = ptr->next;
    delete ptr;

    return newNode;
}
```

### 5. Write a function
```cpp
ListNode* ListConcat(ListNode* list1, ListNode* list2)
```
that concatenates the items in list2 to the end of list1 and returns the resulting list.

```cpp
ListNode* ListConcat(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;

    ListNode* lastNode = list1;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    lastNode->next = list2;

    return list1;
}
```
