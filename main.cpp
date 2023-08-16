
#include "main.h"

using namespace std;

int main(){
    int userOption = -1;

    while(userOption != 0){

        // 0 = Exit
        // 1 = Customer page
        // 2 = Staff Page
        
        userOption = userSelectionMenu();
    
        if(userOption == 1){

        }else if(userOption == 2){

            unordered_map<string, string> map; 
            loadLoginInfo(map);
            
            userOption = login(map); // return 1 for success, 0 for exit

            
            if(userOption == 1){

                while(userOption != 0){

                    userOption = staffPage();

                    // "0. Return to main menu"
                    // "1. Print All Available Vehicles"
                    // "2. Add a Vehicle"
                    // "3. Remove a Vehicle"
                    // "4. Change a Vehicle Amount"

                    if(userOption == 1){
                        printVehicles();
                    }else if(userOption == 2){
                        addVehicle();
                    }else if(userOption == 3){
                        removeVehicle();
                    }else if(userOption == 4){
                        changeAmount();
                    }
                    
                }





            }else{
                //reset user option to original main menu choice to ensure main menu loop
                userOption = 2;
            }
        }
    }

    cout << "Exitting Program." << endl;
        
    return 0;
}

