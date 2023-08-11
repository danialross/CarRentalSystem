#include "userSelection.h"

int userSelectionMenu(){

    cout << "Welcome to the Car Rental System." << endl;

    string buffer;
    bool isValid = true;

    // input validation 
    do{
        if(!isValid){
            cout << endl;
            cout << "Invalid Input" << endl;
            cout << endl;
        }

        cout << "0. Exit" << endl;
        cout << "1. Customer Page" << endl;
        cout << "2. Staff Page" << endl;
        cout << "Please Select 0,1 or 2." << endl;
        cout << "Your option : "; cin >> buffer;  
        

        if(buffer.length() == 1){
            
            if(isdigit(buffer[0])){
                                
                if(stoi(buffer) >= 0 && stoi(buffer) <= 2){
                    break;
                }
            }
        }

        isValid = false;
        
    }while(!isValid);

    cout << string(30,'*') << endl;

    return stoi(buffer);

} 