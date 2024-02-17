#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Welcome to the CODSOFT Calculator!" << endl;
    cout << "Please enter the first number: ";
    cin >> num1;

    cout << "Please enter the operation (+, -, *, /): ";
    cin >> op;

    cout << "Please enter the second number: ";
    cin >> num2;

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error! Division by zero is not allowed." << endl;
            break;
        default:
            cout << "Invalid operation! Please enter one of the following: +, -, *, /" << endl;
    }

    return 0;
}
