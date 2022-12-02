# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>

# include "register_handling.h"
# include "hero_handling.h"

using namespace std;

/////ADD//////////////

    bool operator ==(hero_type const a,
                     hero_type const b){
        
        if(a.name == b.name &&
           a.bithyear == b.bithyear &&
           a.weight == b.weight &&
           a.hair_color == b.hair_color){
                if (a.intrest.size() == b.intrest.size()){
                    for( int i = 0; i< a.intrest.size(); i++){
                        if(a.intrest.at(i) != b.intrest.at(i)){
                            return false;
                            }
                        }
                    return true;
                    }
                }

        return false;
        }

//////////

    bool sort_by_name(hero_type const a,
                      hero_type const b){

        return a.name < b.name;

                      }

//////////

    bool check_for_existing_hero(register_type const item,
                                 hero_type     const hero){

        for(int i = 0; i < item.size(); i++){
            if(hero == item.at(i)){
                return true;
            }
        }
        return false;
    }

///////////

    void feed_struct(hero_type & hero){

        stringstream ss;
        string str;
        string color;
        string num;
        string flo;
        int like;    
        
        
        cin>>str>>num>>flo>>color;
        hero.name = str;
        hero.bithyear = num;
        hero.weight = flo;
        hero.hair_color = color;
        getline(cin , str);
        ss.str(str);
            while(ss >> like){
                hero.intrest.insert(hero.intrest.begin(),like);
                    }
        sort(hero.intrest.begin(), hero.intrest.end());

    }

//////////

    void add(register_type & heroes){

        hero_type hero;

        get_register_1(heroes);

            while(true){

                cout<<"Enter hero information:"<<endl;

                    feed_struct(hero);

                    if(check_for_existing_hero(heroes,hero)){
                        cout<<"Hero already in register. ";
                    }
                    else{
                        heroes.push_back(hero);
                        sort(heroes.begin(),heroes.end(),sort_by_name);
                        add_to_register_1(heroes);
                        cout<<"The hero was added to the register on file REGISTER_1.TXT"<<endl;
                        break;
                    }
            }
    }

/////SEARCH////////////

    void print_hero(hero_type const item){

        cout.width(10); 
        cout<<left<<item.name;
        cout.width(11); 
        cout<<left<<item.bithyear;
        cout.width(7); 
        cout<<item.weight;
        cout.width(11); 
        cout<<item.hair_color;
        cout.width(7);
                
            for( int i = 0; i < item.intrest.size();i++)
                {
                  cout<<right<<setw(3)<<item.intrest.at(i);
                }
                  cout<<endl;
    }

////////

    void print_matches(register_type & matches){

        for(int i = 0; i < matches.size(); i++){
            print_hero(matches.at(i));
        }

    }

////////

    bool compare_matches(hero_type const item,
                         int const compare){
        
        for (int i = 0; i < item.intrest.size(); i++){
            if(compare == item.intrest.at(i)){
                return true;
                }
        }
        return false;
    }

////////

    void search_register(register_type & heroes,
                         register_type & matches,
                         int const intrest){

        get_register_1(heroes);

            for(int i = 0; i < heroes.size(); i++){
                if(compare_matches(heroes.at(i),intrest)){
                    matches.push_back(heroes.at(i));
                    }
                }
            }

/////////

    void search(register_type & heroes,
                register_type & matches){

        int like;

        cout<<"Enter your interests (at least one between 1 and 15): ";
        cin>>like;
        search_register( heroes,
                         matches,
                         like);
        cout<<"There are "<<matches.size()<<" matching heroes."<<endl;
        cout<<"Hero name Birth year Weight Hair color Interests"<<endl;
        cout<<"===================================================="<<endl;
        print_matches(matches);
        matches.clear();
    }
    