#include <iostream>

unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int number;

    std::cout << "Enter a non-negative integer: ";
    if (!(std::cin >> number) || number < 0) {
        std::cout << "Invalid input! Please enter a non-negative integer." << std::endl;
        return 1;
    }

    unsigned long long iterativeResult = factorialIterative(number);
    unsigned long long recursiveResult = factorialRecursive(number);

    std::cout << "\n--- Results ---" << std::endl;
    std::cout << "Iterative Factorial of " << number << " is: " << iterativeResult << std::endl;
    std::cout << "Recursive Factorial of " << number << " is: " << recursiveResult << std::endl;

    return 0;
}

/*
Sample Output: 

Enter a non-negative integer: 5

--- Results ---
Iterative Factorial of 5 is: 120
Recursive Factorial of 5 is: 120
*/