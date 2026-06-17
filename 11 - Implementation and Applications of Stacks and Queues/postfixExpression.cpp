#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>

void evaluatePostfix(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;
    std::stack<int> s;

    while (ss >> token) {
        // Check if the token is a binary operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Postfix evaluation requires at least two operands
            if (s.size() < 2) {
                std::cout << "Error: Invalid expression\n";
                return;
            }

            // Pop the top two elements
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            // Perform the calculation based on the operator
            if (token == "+") {
                s.push(operand1 + operand2);
            } else if (token == "-") {
                s.push(operand1 - operand2);
            } else if (token == "*") {
                s.push(operand1 * operand2);
            } else if (token == "/") {
                if (operand2 == 0) {
                    std::cout << "Error: Division by zero\n";
                    return;
                }
                s.push(operand1 / operand2); // Integer division
            }
        } else {
            // Try to parse the token as an integer and push it to the stack
            try {
                int number = std::stoi(token);
                s.push(number);
            } catch (const std::invalid_argument&) {
                std::cout << "Error: Invalid token '" << token << "'\n";
                return;
            }
        }
    }

    // The stack must contain exactly one element at the end
    if (s.size() == 1) {
        std::cout << s.top() << "\n";
    } else if (!s.empty()) {
        std::cout << "Error: Invalid expression\n";
    }
}

int main() {
    std::string line;

    // Read input line by line until a blank line is encountered
    while (std::getline(std::cin, line)) {
        if (line.empty() || line == "\r") {
            break;
        }
        evaluatePostfix(line);
    }

    return 0;
}

/*
Sample Output: 

76
76

78 6 +
84

78 6 + 9 2 - /
12
*/