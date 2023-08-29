#include <bits/stdc++.h>
using namespace std;
int main(){

srand(time(0));         //Differnt random number is generated every time program is run
int variable = rand()%100 + 1;          //Random number will be generated in the range [1,100]
int num;
cout << "Enter the Number between 1-100: ";
cin >> num;
int total_Number_Of_Guesses = 0;

while(true){
    if(num == variable){
        cout << "Congratulations ! You guessed the correct number in " << total_Number_Of_Guesses << " number of guesses." << endl;
        break;
    }
    else if(num > variable){
        cout << "Try guessing some smaller number than " << num << "." << endl;
        total_Number_Of_Guesses++;
        cin >> num;
    }
    else{
        cout << "Try guessing some bigger number than " << num << "." << endl;
        total_Number_Of_Guesses++;
        cin >> num;
    }
}

return 0;
}