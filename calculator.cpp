#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "==============================\n";
    cout << "     BASIC CALCULATOR\n";
    cout << "==============================\n\n";

    // Take input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "\nChoose an operation (+, -, *, /): ";
    cin >> operation;

    cout << "\nResult: ";

    // Perform operation
    switch(operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << (num1 + num2);
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << (num1 - num2);
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << (num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                cout << num1 << " / " << num2 << " = " << (num1 / num2);
            else
                cout << "Error! Division by zero is not allowed.";
            break;
        default:
            cout << "Invalid operation selected!";
    }

    cout << "\n\nThank you for using the calculator!\n";

    return 0;
}
