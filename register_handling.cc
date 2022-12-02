# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <algorithm>

# include "hero_handling.h"
# include "register_handling.h"

using namespace std;

/////////////////////////

    void feed_struct_from_stream(vector<hero_type> & item,
                                 istream & read_from){

        hero_type hero;
        string text;
        stringstream ss; 
        int num;

        getline(read_from , text);
        ss.str(text);
        
        ss >> hero.name 
         >> hero.bithyear
         >> hero.weight
         >> hero.hair_color;
            while(ss >> num){ 
                hero.intrest.push_back(num);
                }
        item.push_back(hero);
        }

/////////

    void get_register_1(vector<hero_type> & item ){
        
        ifstream read_from;


        read_from.open("register_1.txt");
            while(!read_from.eof()){
                feed_struct_from_stream(item,read_from);
            }
        read_from.close();
    }

///////////////////////

    void print_to_stream(hero_type const item,
                         ostream & write_to){

        write_to<<" "<<item.name<<" "<<item.bithyear
        <<" "<<item.weight<<" "<<item.hair_color;
            for( int i = 0; i < item.intrest.size();i++){
                write_to<<" "<<item.intrest.at(i);
                    }
        write_to<<endl;
    }

/////////

    void add_to_register_1(vector<hero_type> & item){

        ofstream write_to;
        string text;

        write_to.open("register_1.txt");
            for(int i = 0; i < item.size(); i++){
                print_to_stream(item.at(i), write_to);
            }
        write_to.close();
    }
//////////////////////////
    
