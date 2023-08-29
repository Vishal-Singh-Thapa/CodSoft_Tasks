#include <bits/stdc++.h>
using namespace std;

void createMapping(map<int, char>&mp){
    for(int i=1; i<=9; i++){
        mp[i] = ' ';
    }
}

bool checkResult(map<int, char>&mp){
    //Check for first row (1-2-3)
    if(mp[1] != ' ' && mp[2] != ' ' && mp[3] != ' '){
        if(mp[1] == mp[2] && mp[1] == mp[3] && mp[2] == mp[3]){
            return true;
        }
    }
    //Check for second row (4-5-6)
    if(mp[4] != ' ' && mp[5] != ' ' && mp[6] != ' '){
        if(mp[4] == mp[5] && mp[4] == mp[6] && mp[5] == mp[6]){
            return true;
        }
    }
    //Check for third row (7-8-9)
    if(mp[7] != ' ' && mp[8] != ' ' && mp[9] != ' '){
        if(mp[7] == mp[8] && mp[7] == mp[9] && mp[8] == mp[9]){
            return true;
        }
    }
    //Check for first column (1-4-7)
    if(mp[1] != ' ' && mp[4] != ' ' && mp[7] != ' '){
        if(mp[1] == mp[4] && mp[4] == mp[7] && mp[1] == mp[7]){
            return true;
        }
    }
    //Check for second column (2-5-8)
    if(mp[2] != ' ' && mp[5] != ' ' && mp[8] != ' '){
        if(mp[2] == mp[5] && mp[5] == mp[8] && mp[2] == mp[8]){
            return true;
        }
    }
    //Check for third column (3-6-9)
    if(mp[3] != ' ' && mp[6] != ' ' && mp[9] != ' '){
        if(mp[3] == mp[6] && mp[3] == mp[9] && mp[6] == mp[9]){
            return true;
        }
    }
    //Check for 1st diagonal (1-5-9)
    if(mp[1] != ' ' && mp[5] != ' ' && mp[9] != ' '){
        if(mp[1] == mp[5] && mp[1] == mp[9] && mp[5] == mp[9]){
            return true;
        }
    }
    //Check for 2nd diagonal (3-5-7)
    if(mp[3] != ' ' && mp[5] != ' ' && mp[7] != ' '){
        if(mp[3] == mp[5] && mp[5] == mp[7] && mp[3] == mp[7]){
            return true;
        }
    }

    return false;
}

void show3X3Board(map<int, char>&mp){
    cout << "    |    |    " << endl;
    cout << " " << mp[1] << "  |  " << mp[2] << " |  " << mp[3] << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << " " << mp[4] << "  |  " << mp[5] << " |  " << mp[6] << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << " " << mp[7] << "  |  " << mp[8] << " |  " << mp[9] << endl;
    cout << "    |    |    " << endl;
}

bool checkForDraw(map<int, char>&mp){
    for(auto i:mp){
        if(i.second == ' '){
            return false;
        }
    }
    return true;
}

int main(){
    map<int, char>mp;
    createMapping(mp);

    cout << "-----------------------------Wlecome----------------------------------"<<endl;
    cout << "    |    |    " << endl;
    cout << " 1  |  2 |  3" << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << " 4  |  5 |  6" << endl;
    cout << "____|____|____" << endl;
    cout << "    |    |    " << endl;
    cout << " 7  |  8 |  9" << endl;
    cout << "    |    |    " << endl;
    cout << endl << "----> Each box is numbered as shown, choose position accordingly.." << endl << endl;

    bool firstPlayer = true;
    //If firstPlayer = true, player1 turn
    //If firstPlayer = false, player2 turn

    char ch1, ch2;

    cout << "Enter your choice ('O' or 'X'): ";     //Sign assigned to player1
    cin >> ch1;
    if(ch1 == 'O'){
        ch2 = 'X';
    }
    else{
        ch2 = 'O';
    }

    cout << endl << "Player 1 is assigned " << ch1 << " symbol." << endl;
    cout << "Player 2 is assigned " << ch2 << " symbol." << endl;  

    show3X3Board(mp);
    bool isFinished = false;
    
    while(!isFinished){
        //Check for draw match
        if(checkForDraw(mp)){
            cout << "Draw match....No winner" << endl;
            char ch;
            cout << "Want to play again? Y/N : ";
            cin >> ch;
            if(ch == 'Y'){
                map<int, char>mp1;
                createMapping(mp1);
                mp = mp1;
                continue;
            }
            else{
                break;
            }
        }

        else if(firstPlayer){
            //Run the loop till correct position is entered
            while(true){
                int position;
                cout << "Player-1 Turn: Enter the position to insert(1-9) " << ch1 << ": ";
                cin >> position;
                //Invalid position if it's not empty
                if(mp[position] != ' '){
                    cout << "Invalid Position...Please Enter again" << endl;
                    continue;
                }
                else{
                    mp[position] = ch1;
                    show3X3Board(mp);
                    cout << endl;

                    //Check for result
                    if(checkResult(mp)){
                        cout << "Congratulations!!! Player 1 Wins......." << endl;
                        cout << "-------------------------------------------------------------------------------------------" << endl;
                        char ch;
                        cout << "Want to play again? Y/N : ";
                        cin >> ch;
                        if(ch == 'Y'){
                            map<int, char>mp1;
                            createMapping(mp1);
                            mp = mp1;
                            firstPlayer = true;
                            break;
                        }
                        else{
                            isFinished = true;
                            break;
                        }
                    }
                    else if(!checkResult(mp)){
                        firstPlayer = false;
                        break;
                    }
                }
            }
        }

        else if(!firstPlayer){
            //Run the loop till correct position is entered
            while(true){
                int position;
                cout << "Player-2 Turn: Enter the position to insert(1-9) " << ch2 << ": ";
                cin >> position;
                //Invalid position if it's not empty
                if(mp[position] != ' '){
                    cout << "Invalid Position...Please Enter again" << endl;
                    continue;
                }
                else{
                    mp[position] = ch2;
                    show3X3Board(mp);
                    cout << endl;

                    //Check for result
                    if(checkResult(mp)){
                        cout << "Congratulations!!! Player 2 Wins......." << endl;
                        cout << "-------------------------------------------------------------------------------------------" << endl;
                        char ch;
                        cout << "Want to play again? Y/N : ";
                        cin >> ch;
                        if(ch == 'Y'){
                            map<int, char>mp1;
                            createMapping(mp1);
                            mp = mp1;
                            firstPlayer = true;
                            break;
                        }
                        else{
                            isFinished = true;
                            break;
                        }
                    }
                    else if(!checkResult(mp)){
                        firstPlayer = true;
                        break;
                    }
                }
            }  
        }
    }
return 0;
}