// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using time_arr = vector<double>;

/////STRUCT////////////////

    struct runner
    {
        string         surename{}; 
        string         lastname{}; 
        string         club{};     
        vector<double> times; 
    };
    
using runner_arr = vector<runner>;

////SORTING_ARRAYS///////////

    bool placement(runner const a,
                   runner const b){
    
        return a.times.at(0) < b.times.at(0);
    }

////////

    void sort_times(vector<double>& item){

        sort(item.begin() , item.end());
    }

////////


    void sorter(runner_arr& item){

        for(auto & person : item){
            sort_times(person.times);
            }

        sort(item.begin(), item.begin() + item.size() , placement );
    
    }

/////FEED_STRUCT/ARR//////

    bool more_time(runner& item){

        double time;

        cin>>time;
            if(time == -1){
                return false;
            }
            else{
            item.times.insert(item.times.begin(),time);
            return true;
            }
    }

///////////


    void feed_time(runner& item){

        while(more_time(item)){
            ;
            }
        }

//////////

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

/////PRINT//////////////

    string print_surename(runner const item){

        return item.surename;
    }

/////////


    void print_struct(runner const item){

        cout<<fixed<<setw(9)<<item.surename
        <<fixed<<setw(10)<<item.lastname;
            for(int i = 0; i < item.club.size();i++){
                if(item.club[i] == '_'){
                    item.club[i] = ' ';
                }
            }
        cout<<fixed<<setw(16)<<item.club<<": ";
            for(double i = 0.0 ; i < item.times.size(); i++){
                if(i == 0.0){
                    cout<<fixed<<setw(2)<<setprecision(2)<<item.times.at(i);
                }
                else{
                    cout<<fixed<<setw(6)<<setprecision(2)<<item.times.at(i);
                }
                }
        cout<<endl;
    }

//////////////////////

    int main(){

        runner_arr participants;
        int counter = 0;
        runner person;

        cout<<"Mata in deltagare:"<<endl;

            while(feed_struct(person)){//Matar in deltagare i array och fyller på med namn och klubb
                participants.push_back(person);    
                }

            for(auto & person : participants){//Matar in tider på deltagare
                cout<<"Tider "<<print_surename(person)<<":";
                feed_time(person);
            }

        sorter(participants);//sorteras användare

        cout<<"Efternamn   Förnamn           Klubb: Tider"<<endl
        <<"=============================================="<<endl;
            for(auto & person : participants){
                    print_struct(person);
                    }
    }
