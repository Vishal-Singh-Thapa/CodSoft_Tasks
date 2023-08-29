#include <bits/stdc++.h>
using namespace std;

void addTask(vector<pair<string, bool>>&list){
    string s;
    cout << "ADD TASK IN A LIST------->" << endl;
    cout << "Enter the task decription: ";

    /* cin>> will leave newlines in the buffer when the user presses enter. 
    getline() reads this as the user having pressed enter to "skip" the input */
     
    cin.ignore(); //This statement is used to ignore newlines 
    getline(cin, s);

    char ch;
    bool completed = false;
    cout << "Is the task completed? Y/N: ";
    cin >> ch;
    if(ch == 'Y'){
        completed = true;
    }
    pair<string, bool>p = make_pair(s, completed);

    list.push_back(p);
    cout << "Task added successfully!!" << endl << endl;
}

void viewTasks(vector<pair<string, bool>>&list){
    char ch;
    cout << "Want to view all tasks? Y/N" << endl;
    cin >> ch;
    if(ch == 'Y' || ch == 'y'){
        for(int i=0; i<list.size(); i++){
            cout << "Task-" << i+1 << ":" << endl;
            cout << "Description: " << list[i].first << endl;
            if(list[i].second){
                cout << "Completed: " << "Yes" << endl; 
            }
            if(!list[i].second){
                cout << "Completed: " << "No" << endl; 
            }
            cout << endl;
        }
    }
    else{
        while(true){
            int t;
            cout << "Enter the task number to be viewed: ";
            cin >> t;
            cout << "Task-" << t << ":" << endl;
            cout << "Description: " << list[t-1].first << endl;
            if(list[t-1].second){
                cout << "Completed: " << "Yes" << endl; 
            }
            if(!list[t-1].second){
                cout << "Completed: " << "No" << endl; 
            }
            cout << endl;

            char ch;
            cout << "Want to view more tasks? Y/N: ";
            cin >> ch;
            if(ch == 'Y' || ch == 'y'){
                cout << endl;
                continue;
            }
            else{
                break;
            }
        }
    }
}

void markTasks(vector<pair<string, bool>>&list){
    char ch;
    cout << "Mark all the tasks completed? Y/N: ";
    cin >> ch;
    if(ch == 'Y' || ch == 'y'){
        for(int i=0; i<list.size(); i++){
            list[i].second = true;
        }
        cout << "All Tasks marked completed successfuly !!" << endl;
    }
    else{
        while(true){
            int t;
            cout << "Enter the task number to be mark completed: ";
            cin >> t;
            if(list[t-1].second == true){
                cout << "Task-" << t << " was already completed." << endl;
            }
            else{
                list[t-1].second = true;
                cout << "Task-" << t << " marked completed successfuly !!" << endl;
            }
            cout << endl;

            char ch;
            cout << "Want to mark more tasks completed? Y/N: ";
            cin >> ch;
            if(ch == 'Y' || ch == 'y'){
                cout << endl;
                continue;
            }
            else{
                break;
            }
        }
    } 
}

void removeTask(vector<pair<string, bool>>&list){
    char ch;
    cout << "Want to erase all the tasks? Y/N: ";
    cin >> ch;
    if(ch == 'Y' || ch == 'y'){
        list.clear();
        cout << "All Tasks are removed successfuly !!" << endl;
    }
    else{
        while(true){
            int t;
            cout << "Enter the task number to be removed: ";
            cin >> t;
            list.erase(list.begin()+t-1);
            cout << "Task-" << t << " is removed successfuly !!" << endl;
            cout << endl;

            char ch;
            cout << "Want to remove more tasks? Y/N: ";
            cin >> ch;
            if(ch == 'Y' || ch == 'y'){
                cout << endl;
                continue;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    cout << "-----------------------------------------TO DO LIST-----------------------------------------" << endl;
    cout << "Follwong operations can be performed: " << endl;
    cout << "1. -> Add Task in the list." << endl;
    cout << "2. -> View Tasks in the list." << endl;
    cout << "3. -> Mark Task as Completed." << endl;
    cout << "4. -> Remove Task from the list." << endl;
    cout << endl;

    //Vector is used as a list, 
    /*Each cell of vector conatins a pair value in which first value of pair stores the 
    description and second value of pair indicates whether the task is completed or not */

    vector<pair<string, bool>>list;

    while(true){
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: 
                addTask(list);
                break;
            case 2:
                viewTasks(list);
                break;
            case 3:
                markTasks(list);
                break;
            case 4:
                removeTask(list);
                break;
            default:
                cout << "Invalid choice.." << endl;
                break;
        }
        char ch;
        cout << "Want to continue? Y/N: ";
        cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            cout << endl;
            continue;
        }
        else{
            break;
        }
    }

return 0;
}