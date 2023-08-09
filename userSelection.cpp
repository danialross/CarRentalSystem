#include "userSelection.h"

int userSelectionMenu(){

    cout << "Welcome to the Car Rental System." << endl;

    string buffer;
    bool isValid = true;

    // input validation 
    do{
        if(!isValid){
            cout << "Invalid Input" << endl;
        }

        cout << "1. Customer Page" << endl;
        cout << "2. Staff Page" << endl;
        cout << "3. Exit" << endl;
        cout << "Please Select 1,2 or 3." << endl;
        cout << "Your option : "; cin >> buffer;  
        cout << string(30,'*') << endl;

        if(buffer.length() == 1){
            
            if(isdigit(buffer[0])){
                                
                if(stoi(buffer) >= 1 && stoi(buffer) <= 3){
                    break;
                }
            }
        }

        isValid = false;
        
    }while(!isValid);

    return stoi(buffer);

} 