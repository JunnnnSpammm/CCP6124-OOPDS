## Section 2: Review Questions and Exercises

### Suppose that the classes Dog and Cat derive from Animal, which in turn derives from Creature. Suppose further that pDog, pCat, pAnimal, and pCreature are pointers to the respective classes. Suppose that Animal and Creature are both abstract classes.

### 1. Will the statement compile?
```cpp
Animal a;
```

No

### 2. Will the statement compile?
```cpp
pAnimal = new Cat;
```

Yes

### 3. Will the statement compile?
```cpp
pCreature = new Dog;
```

Yes

### 4. Will the statement compile?
```cpp
pCat = new Animal;
```

No

### 5. Rewrite the following two statements to get them to compile correctly.
```cpp
pAnimal = new Dog;
pDog = pAnimal;
```

```cpp
pAnimal = new Dog;
pDog = dynamic_cast<Dog*>(pAnimal);
```
