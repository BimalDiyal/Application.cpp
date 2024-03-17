#include <iostream>

int main() {
    char op;
    double num1, num2;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cerr << "Error: Division by zero is undefined.\n";
                return 1;  // Exit with an error code
            }
            break;
        default:
            std::cerr << "Error: Invalid operator.\n";
            return 1;  // Exit with an error code
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
