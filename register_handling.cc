// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <algorithm>

# include "hero_handling.h"
# include "register_handling.h"

using namespace std;

////////////////////////////////////////////////////////////
/////ADD////////////////////////////////////////////////////


    bool check_for_existing_hero(register_type const item,
                                 hero_type     const hero){

        for(int i = 0; i < item.size(); i++){
            if(hero == item.at(i)){
                return true;
            }
        }
        return false;
    }


////////

    void feed_struct_from_stream(register_type & item,
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

    void add_to_register(register_type & item,
                           string const file_name){

        ofstream write_to;
        string text;

        if(!(write_to.is_open())){
            cout<<"Did not open file in add_to_register!";
        }

        write_to.open(file_name);
            for(int i = 0; i < item.size(); i++){
                print_to_stream(item.at(i), write_to);
            }
        write_to.close();
    }

/////////

    void get_register(register_type & item,
                        string const file_name){
        
        ifstream read_from;

        if(!(read_from.is_open())){
            cout<<"Did not open file in get_register!";
        }

        read_from.open(file_name);
            while(!read_from.eof()){
                feed_struct_from_stream(item,read_from);
            }
        read_from.close();
    }

////////

    void add(register_type & heroes,
             string const file_name){

        hero_type hero;

        get_register(heroes,file_name);

            while(true){

                cout<<"Enter hero information:"<<endl;

                    feed_struct(hero);

                    if(check_for_existing_hero(heroes,hero)){
                        cout<<"Hero already in register. ";
                    }
                    else{
                        heroes.push_back(hero);
                        sort(heroes.begin(),heroes.end(),sort_by_name);
                        add_to_register(heroes,file_name);
                        cout<<"The hero was added to the register on file "<<file_name<<endl;
                        break;
                    }
            }
    }

/////////////////////////////////
////SEARCH///////////////////////

    void print_matches(register_type & matches){

        for(int i = 0; i < matches.size(); i++){
            print_hero(matches.at(i));
        }

    }

////////

    void search_register(register_type & heroes,
                         register_type & matches,
                         int const intrest,
                         string const file_name){

        get_register(heroes,file_name);

            for(int i = 0; i < heroes.size(); i++){
                if(compare_matches(heroes.at(i),intrest)){
                    matches.push_back(heroes.at(i));
                    }
                }
            }

///////

    void search(register_type & heroes,
                register_type & matches,
                string const file_name){

        int like;

        cout<<"Enter your interests (at least one between 1 and 15): ";
        cin>>like;
        search_register( heroes,
                         matches,
                         like,
                         file_name);
        cout<<"There are "<<matches.size()<<" matching heroes."<<endl;
        cout<<"Hero name  Birth year  Weight  Hair color  Interests"<<endl;
        cout<<"===================================================="<<endl;
        print_matches(matches);
        matches.clear();
    }
