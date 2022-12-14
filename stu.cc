// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
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
   
    getline(cin,str); 
    item.club = str;

    return true;
    }

/////PRINT//////////////

    string print_surename(runner const item){

        return item.surename;
    }

/////////

    void print_struct(runner & item){

        cout<<fixed<<setw(9)<<item.lastname
        <<fixed<<setw(10)<<item.surename
        <<fixed<<setw(16)<<item.club<<":";

            for(double i = 0.0 ; i < item.times.size(); i++){
                cout<<" "<<setprecision(2)<<item.times.at(i);
            }
        cout<<endl;
    }

//////////////////////

    int main(){

        runner_arr participants;
        int counter = 0;
        runner person;

        cout<<"Mata in deltagare:"<<endl;

            while(feed_struct(person)){//Matar in deltagare i array och fyller p?? med namn och klubb
                participants.push_back(person);    
                }

            for(auto & person : participants){//Matar in tider p?? deltagare
                cout<<"Tider "<<print_surename(person)<<": ";
                feed_time(person);
            }

        sorter(participants);//sorteras anv??ndare

        cout<<"Efternamn   F??rnamn           Klubb: Tider"<<endl
        <<"=========================================="<<endl;
            for(auto & person : participants){
                    print_struct(person);
                    }
    }
