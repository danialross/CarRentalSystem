
#include "main.h"

using namespace std;

int main(){
    int userOption = 0;

    while(userOption != 3){

        // 1 = Customer page
        // 2 = Staff Page
        // 3 = Exit
        userOption = userSelectionMenu();
    
        if(userOption == 1){

        }else if(userOption == 2){

            unordered_map<string, string> map; 
            loadLoginInfo(map);
            
            userOption = login(map); // return 1 for success, 0 for exit

            
            if(userOption == 1){

                // userOption = staffPage();
                // "1. Add a Vehicle"
                // "2. Remove a Vehicle"
                // "3. Change a Vehicle"
                // "4. Return to main menu"




            }else{
                //reset user option to original main menu choice to ensure main menu loop
                userOption = 2;
            }
        }
    }

    cout << "Exitting Program." << endl;
        
    return 0;
}

