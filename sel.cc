// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>

  using namespace std;

///cel_kel/////////////

    double cel_kel(int const item){
        
        double temp;

        temp = item;
        return temp + 273.15;
    }
    
///cel_far////////////

    double cel_far(int const item){

        double temp;

        temp = item;
        return (temp * 1.8) + 32;
    }

///cel_rem/////////////

    double cel_rem(int const item){

        double temp;

        temp = item;
        return temp * 0.8;
    }

///average////////////

    double average(string long_word, string short_word){
      
      return (long_word.size() + short_word.size()) / 2;;
    }
//Main///////////////
  
int main(){

///Variable//////////

    int start;
    int end;
    int letters = 0;
    int num = 0;
    int blank = 0;
    char cha;
    bool no_text_buffer = true;
    string str;
    string short_word;
    string long_word;
    

///////////////////////

    cout<<"Del 1: Temperaturtabell"<<endl;    
    do{
    cout<<"Ange startvärde: ";
    cin>>start;
    cout<<"Ange slutvärde: ";
    cin>>end;
    if(start > end){
        cout<<"Felaktigt slutvärde!"<<endl;
        cin.ignore(1000,'\n');
    }
    }while(start > end);
    cout<<endl<<endl;


    cout<<"Celsius Kelvin Fahrenheit Reaumur"<<endl//Skriver ut fel antal decimaler
    <<"---------------------------------------"<<endl;
        while(start<=end){
            cout<<setw(7)<<start<<setw(7)<<cel_kel(start)
            <<setw(11)<<cel_far(start)<<setw(8)<<cel_rem(start)<<endl;
            start++;
        }
    cout<<"---------------------------------------"<<endl<<endl;
    cin.ignore(1000,'\n');

  cout<<"Del 2: Teckenhantering"<<endl;
    for(int i{}; i < 10; i++){
    cin.get(cha);
      if(isdigit(cha)){
        num++;
      }
      if(isalpha(cha)){
        letters++;
      }
      if(isspace(cha)){
        blank++;
      }
    }

  cout<<"Texten innehöll:"<<endl<<"Alfabetiska tecken:"<<letters<<endl
  <<"Siffertecken......:"<<num<<endl<<"Vita tecken.......:"<<blank<<endl<<endl;


  cout<<"Del 3: Ordhantering"<<endl<<"Mata in en text:"<<endl;
  num = 0;

    while(cin>>str){

        no_text_buffer = false;

        if(num == 0){
          short_word = str;
          long_word = str;
        }
        if(str.size() > long_word.size()){
          long_word = str;
        }
        if(str.size() < short_word.size()){
          short_word = str;
        }
        num++;
    }

    if(no_text_buffer){
      cout<<"Inga ord matades in."<<endl;
    }
  
    else{
    cout<<"Texten innehöll "<<num<<" ord."<<endl;
    cout<<"Det kortaste ordet var "<<short_word<<" med "<<short_word.size()<<" tecken."<<endl;
    cout<<"Det längsta ordet var "<<long_word<<" med "<<long_word.size()<<" tecken."<<endl;
    cout<<"Medelordlängden var "<<average(long_word,short_word)<<" tecken."<<endl;
    }
 }
