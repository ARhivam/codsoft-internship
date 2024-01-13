#include<iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "Simple Calculator Program" << endl;
    cout << "-------------------------" << endl;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Choose an operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            break;
    }

    return 0;
}
