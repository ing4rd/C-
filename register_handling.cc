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


    bool check_for_existing_hero(Register_type const & item,
                                 Hero_type     const & hero){

        for(int i = 0; i < item.size(); i++){
            if(hero.name == item.at(i).name){
                return true;
            }
        }
        return false;
    }


////////

    void feed_struct_from_stream(Register_type  & item,
                                 istream        & read_from){

        Hero_type hero;
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

    void add_to_register(Register_type       & item,
                         string        const & file_name){

        ofstream write_to;
        string text;

        write_to.open(file_name);
            for(int i = 0; i < item.size(); i++){
                print_to_stream(item.at(i), write_to);
            }
        write_to.close();
    }

/////////

    void get_register(Register_type       & item,
                        string      const & file_name){
        
        ifstream read_from;

        read_from.open(file_name);
            while(!read_from.eof()){
                feed_struct_from_stream(item,read_from);
            }
        read_from.close();
    }

////////

    void add(Register_type       & heroes,
             string        const & file_name){

        bool new_hero_added = false;

        get_register(heroes,file_name);

            do{

                cout<<"Enter hero information:"<<endl;

                Hero_type hero{};
                feed_struct(hero);

                    if(check_for_existing_hero(heroes,hero)){
                        cout<<"Hero already in register. ";
                    }
                    else{
                        heroes.push_back(hero);
                        sort(heroes.begin(),heroes.end(),sort_by_name);
                        add_to_register(heroes,file_name);
                        cout<<"The hero was added to the register on file "<<file_name<<endl;
                        new_hero_added = true;
                    }
            }while(!(new_hero_added));
    }

/////////////////////////////////
////SEARCH///////////////////////

    void print_matches(Register_type & matches){

        for(int i = 0; i < matches.size(); i++){
            print_hero(matches.at(i));
        }

    }

////////

    void search_register(Register_type       & heroes,
                         Register_type       & matches,
                         int           const   intrest,
                         string        const & file_name){

        get_register(heroes,file_name);

            for(int i = 0; i < heroes.size(); i++){
                if(compare_matches(heroes.at(i),intrest) &&
                 !(check_for_existing_hero(matches,
                                           heroes.at(i)))){
                    matches.push_back(heroes.at(i));
                    }
                }
            }

///////

    void feed_like(vector<int> & item){

        string text;
        int num;
        bool data_has_been_read = false;

            do{
                getline(cin, text);
                stringstream ss{text};

                while(ss >> num){
                    if(num >= 1 && num <= 15){
                        item.push_back(num);
                        data_has_been_read = true;
                            }
                        }
            }while(!data_has_been_read);

        sort(item.begin(),item.end());
    }

////////

    void search(Register_type      & heroes,
                Register_type      & matches,
                string       const & file_name){

        vector<int> like;

        cout<<"Enter your interests (at least one between 1 and 15): ";
        feed_like(like);

            for(int i{}; i < like.size(); i++){
                search_register( heroes,
                                 matches,
                                 like.at(i),
                                 file_name);
                                 }
        cout<<"There are "<<matches.size()<<" matching heroes."<<endl;
        cout<<"Hero name  Birth year  Weight  Hair color  Interests"<<endl;
        cout<<"===================================================="<<endl;
        sort(matches.begin(),matches.end(),sort_by_name);
        print_matches(matches);
        matches.clear();
    }
