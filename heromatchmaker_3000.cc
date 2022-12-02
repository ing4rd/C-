# include <string>
# include <iostream>
# include <vector>
# include <iomanip>

# include "register_handling.h"
# include "hero_handling.h"

using namespace std;
using register_type = vector<hero_type>;
////////////////////////

    int main(){

        int num;
        register_type heroes;
        register_type matches;

        cout<<"Welcome to Hero Matchmaker 3000!"<<endl;
            while(true){
                cout<<"Select: ";
                cin>>num;

                    if(num == 1){
                        add(heroes);
                    }
                    else if(num == 2){
                        search(heroes,
                               matches);
                    }
                    else if(num == 3){
                        cout<<"Terminating Hero Matchmaker 3000!";
                        break;
                    }
                heroes.clear();
            }
    return 0;
    }