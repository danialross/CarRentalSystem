#include "staffPage.h"

int staffPage(){

    cout << "Staff Page." << endl;

    int option = 0;
    string buffer;
    bool isValid = true;

    // input validation 
    do{
        if(!isValid){
            cout << "Invalid Input" << endl;
        }

        cout << "1. Add a Vehicle" << endl;
        cout << "2. Remove a Vehicle" << endl;
        cout << "3. Change a Vehicle" << endl;
        cout << "4. Return to main menu" << endl;
        cout << "Please Select 1,2,3 or 4." << endl;
        cout << "Your option : "; cin >> buffer;  
        cout << string(30,'*') << endl;

        if(buffer.length() == 1){
            
            if(isdigit(buffer[0])){
                                
                if(stoi(buffer) >= 1 && stoi(buffer) <= 4){
                    break;
                }
            }
        }

        isValid = false;
        
    }while(!isValid);

    return stoi(buffer);
        
}

int login(unordered_map<string, string> map){

    string username,password,un,pw;

    while(true){

        cout << "Staff Login" << endl;
        cout << "Enter Username : "; cin >> username;
        cout << "Enter Password : "; cin >> password;

        auto it = map.find(username);

        if(it != map.end() && it->second == password){
            cout << "Login Successfully." << endl;
            return 1;

        }else{
            string tryAgain = "";
            cout << "Incorrect username and/or password, Do you wish to try again? (y/n)" << endl;
            cout << "Your option : " ; cin >> tryAgain;

            while(tryAgain != "y" && tryAgain != "n"){
                cout << "Invalid option, select 'y' or 'n'. " << endl;
                cout << "Your option : " ; cin >> tryAgain;
            }

            if(tryAgain == "n"){
                cout << string(30,'*') << endl;
                return 0;
            }
        }
    }    
}

void loadLoginInfo(unordered_map<string, string>& map){

    string line, username, password;
    ifstream file("loginInformation.txt");

    getline(file,line);

    while(line.length() != 0){
        
        int startIndex = 0;
        int foundIndex = line.find(",");

        username = line.substr(startIndex,foundIndex - startIndex);
        startIndex = foundIndex + 1;
        foundIndex = line.find(';');
        password = line.substr(startIndex,foundIndex - startIndex);

        map.insert({username,password});

        getline(file,line);

    }

}

