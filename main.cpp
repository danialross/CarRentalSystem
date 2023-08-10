
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

            for (const auto& x : map) {
                std::cout << x.first << ": " << x.second << "\n";
            }


        }

    }

    cout << "Exitting Program." << endl;
        
    return 0;
}

