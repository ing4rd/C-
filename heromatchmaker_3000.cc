// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
# include <string>
# include <iostream>
# include <vector>
# include <iomanip>
# include <fstream>

# include "register_handling.h"
# include "hero_handling.h"

using namespace std;
using register_type = vector<hero_type>;


/////////////////////

    bool argument_check(int argc, char** argv){

        ifstream arg_name(argv[1]);

        if(!(argc == 2 && arg_name.is_open())){
                return true;
            }
        return false;
        }

////////////////////////

    void menu_selection(string const & file_name){

        int num;
        register_type heroes;
        register_type matches;

        cout<<"Welcome to Hero Matchmaker 3000!"<<endl;
            do{
                cout<<"1) Add new hero to register file"<<endl
                    <<"2) Find matching heroes"<<endl
                    <<"3) Quit program"<<endl;
                do{
                    cout<<"Select: ";
                cin>>num;
                    }while (num < 1 || num > 3);
                    

                    if(num == 1){
                        add(heroes,
                            file_name);
                    }
                    else if(num == 2){
                        search(heroes,
                               matches,
                               file_name);
                    }
                    else if(num == 3){
                        cout<<"Terminating Hero Matchmaker 3000!";
                    }
                heroes.clear();

            }while(num != 3);

    }


////////////////////////

    int main(int argc, char** argv){

        string exec_prog = argv[0];
        string file_name;


        if(argument_check(argc , argv)){
            cout<<"Incorrect number of arguments!"<<endl
            <<"Usage: "<<exec_prog<<" REGISTERFILE"<<endl;
            return 1;
        }

        file_name = argv[1];

        menu_selection(file_name);

        return 0;
    
    }
