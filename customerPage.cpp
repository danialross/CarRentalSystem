#include "customerPage.h"

int customerPage(){

    int option = 0;
    string buffer;
    bool isValid = true;

    // input validation 
    do{
        if(!isValid){
            cout << "Invalid Input" << endl;
        }
        cout << "Customer Page" << endl;
        cout << "0. Return to Main Menu" << endl;
        cout << "1. Rent a Vehicle" << endl;
        cout << "2. Return a Vehicle" << endl;
        cout << "Your Option : "; cin >> buffer; 
        cout << string(30,'*') << endl;

        if(buffer.length() == 1){
            
            if(isdigit(buffer[0])){
                                
                if(stoi(buffer) >= 0 && stoi(buffer) <= 2){
                    break;
                }
            }
        }

        isValid = false;
        
    }while(!isValid);

    return stoi(buffer);
}

//rent a car
void rent(){
    
    string line, modal;
    bool exist = false;

    //case sensitive

    cout << "Enter vehicle to rent (Model Make)." << endl;
    cout << "Your Option : " ; 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, modal);

    //since 6 is the smallest car length i.e "BMW X5" input less then 6 is not valid
    while(modal.length() < 6){
        cout << "Invalid option, try again." << endl;
        cout << "Your Option : ";
        getline(cin, modal);
    }

    ofstream output("temp.txt");
    ifstream input("carDatabase.txt");

    getline(input,line);

    while(line.length() != 0){

        if(line.find(modal) != -1){

            int amountIndex = line.find(",") + 2;
            string amount = line.substr(amountIndex,line.length() - amountIndex);

            exist = true;

            if(stoi(amount)-1 != 0){
                output << modal << ", " << stoi(amount)-1 << endl;

            }

            cout << endl;
            cout << modal << " has now been rented." << endl;
            cout << "New Value is now { " << modal << ", " << stoi(amount)-1 << " }." << endl;
            cout << endl;

        }else{
            if(output.is_open()){
                output << line << endl;
            }else{
                cout << "Error occurred when accessing item from database." << endl;
            }
        }

        getline(input,line);
    } 

    if(!exist){
        cout << endl;
        cout << "Vehicle does not exist." << endl;
        cout << endl;
    }

    output.close();
    remove("carDatabase.txt");
    rename("temp.txt","carDatabase.txt");

    string rentAnother;
    cout << "Would you like to rent another car? (y/n)" << endl;
        
    cout << "Your Option : " ; cin >> rentAnother;
    rentAnother = tolower(rentAnother[0]);

    while(rentAnother != "y" && rentAnother != "n"){
        cout << "Invalid option, select 'y' or 'n'. " << endl;
        cout << "Your Option : " ; cin >> rentAnother;
    }

    if(rentAnother == "y"){
        rent();

    }else{
        cout << endl;
        cout << "Returning to main page." << endl;
        cout << endl;
    }

}

void returnCar(){
    
}