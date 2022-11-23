// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using time_arr = vector<double>;

////////////////////////

    struct runner
    {
        string         surename; 
        string         lastname; 
        string         club;     
        vector<double> times;    
    };
    
using runner_arr = vector<runner>;

////////////////////////

    bool feed_struct(runner& item){

    string str;
    string temp;


    cin>>str;
        if(str == "KLAR"){
            return false;
        }
    item.surename = str;
    cin>>str;
    item.lastname = str;
    cin>>str;
    temp = str;
        if(cin.peek() != '\n'){
            cin>>str;
            temp = temp + '_' + str;
        }
    item.club = temp;

    return true;

    }
///////////////////////

    void print_struct(runner item){

    int num;

        cout<<fixed<<setw(9)<<item.surename
        <<fixed<<setw(10)<<item.lastname;
            for(int i = 0; i < item.club.size();i++){
                if(item.club[i] == '_'){
                    item.club[i] = ' ';
                }
            }

        cout<<fixed<<setw(16)<<item.club<<":"<<endl;////////////////////////////Ska lägga till tider.        
    }

//////////////////////

    bool more_time(runner& item){

        double time;

        cin>>time;
            if(time == -1){
                return false;
            }
        item.times.push_back(time);
        return true;
    }

///////////

    void feed_time(runner& item){

        while(more_time(item)){
        ;}
    }

//////////////////////

    string print_surename(runner item){

        return item.surename;
    }

//////////////////////

    int main(){

        runner_arr participants;
        int counter = 0;
        runner person;

        cout<<"Mata in deltagare:";

            while(feed_struct(person)){
                
            participants.push_back(person);    
                }

            for(auto & person : participants){

                cout<<"Tider "<<print_surename(person)<<":";
                feed_time(person);
            }


        cout<<"Efternamn   Förnamn           Klubb: Tider"<<endl
        <<"=============================================="<<endl;

            for(auto & person : participants){
                    print_struct(person);
                    }

    }
