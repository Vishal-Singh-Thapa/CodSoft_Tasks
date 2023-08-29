#include <bits/stdc++.h>
using namespace std;
int main(){
    int choice;
    float n1, n2;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "                            Following operations can be performed:" << endl;
    cout << "                            1. Addition" << endl;
    cout << "                            2. Subtraction" << endl;
    cout << "                            3. Multiplication" << endl;
    cout << "                            4. Division" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter the first number: ";
    cin >> n1;
    cout << "Enter the second number: ";
    cin >> n2;
    cout << endl;
    cout << "Enter the operation to be performed (Select the number from the list given above): ";
    cin >> choice;
    cout << endl;
    
    switch(choice){
        case 1:
            cout << "Performing Addition: " << endl;
            cout << "Sum of " << n1 << " and " << n2 << " is " << n1+n2 << "." << endl;
            break;
        case 2:
            cout << "Performing Subtraction: " << endl;
            cout << "Difference of " << n1 << " and " << n2 << " is " << n1-n2 << "." << endl;
            break;
        case 3:
            cout << "Performing Multiplication: " << endl;
            cout << "Product of " << n1 << " and " << n2 << " is " << n1*n2 << "." << endl;
            break;
        case 4:
            cout << "Performing Division: " << endl;
            cout << "Quotient of " << n1 << " and " << n2 << " is " << n1/n2 << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    };
return 0;
}