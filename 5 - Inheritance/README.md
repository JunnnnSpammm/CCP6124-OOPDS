## Section 2: Review Questions and Exercises
### 1. What type of relationship between classes is realized by inheritance?

Inheritance realizes the "Is-a" relationship. This means that a derived class is a specialized version of the base class.

### 2. What is the difference between private members and protected members?

**Private members:** These are accessible only by member functions of the class in which they are declared. Even a derived class cannot access the private members of its base class.

**Protected members:** These are accessible to member functions of the class in which they are declared and to member functions of any derived classes. However, they remain inaccessible to the "outside world" (rest of the program).

### 3. What is the reason that base class constructors are called before derived class constructors?

The base class constructor is called first because the derived class is built "on top of" the base class.

Since the derived class may rely on members, data, or initialization logic defined in the base class, the base class must be fully constructed and initialized before the derived class's specific code begins to execute.