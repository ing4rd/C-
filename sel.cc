// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>

  using namespace std;

//Main///////////////
  
int main(){

///Variable//////////

    int start;
    int end;
    int letters = 0;
    int num = 0;
    int blank = 0;
    double sum = 0;
    double kel;
    double far;
    double rem;
    double average;
    char cha;
    bool no_text_buffer = true;
    string str;
    string short_word;
    string long_word;
    

//////////

    cout<<"Del 1: Temperaturtabell"<<endl;    
      while(true){
        cout<<"Ange startvärde: ";
        cin>>start;
          if(start < -273.15){
            cout<<"Felaktigt startvärde!"<<endl;
            }
          else{
            break;
          }
      }
      do{
        cout<<"Ange slutvärde: ";
        cin>>end;

          if(start > end){
            cout<<"Felaktigt slutvärde!"<<endl;
            cin.ignore(1000,'\n');
                    }
  
        kel = start + 273.15;
        far = (start * 1.8) + 32;
        rem = start * 0.8;

      }while(start > end);


    cout<<"Celsius   Kelvin   Fahrenheit   Reaumur"<<endl
    <<"---------------------------------------"<<endl;
        while(start<=end){
            cout.width(7);
            cout<<start;
            cout.width(9);
            cout<<fixed<<setprecision(2)<<kel;
            cout.width(13);
            cout<<fixed<<setprecision(2)<<far;
            cout.width(10);
            cout<<fixed<<setprecision(2)<<rem<<endl;

            start++;
            kel = start + 273.15;
            far = (start * 1.8) + 32;
            rem = start * 0.8;
        }
    cout<<"---------------------------------------"<<endl<<endl;
    cin.ignore(1000,'\n');

//////////

  cout<<"Del 2: Teckenhantering"<<endl;
    for(int i{}; i < 10; i++){
      cin.get(cha);
        if(isdigit(cha)){
          num++;
        }
        else if(isalpha(cha)){
          letters++;
        }
        else if(isspace(cha)){
          blank++;
        }
    }

  cout<<"Texten innehöll:"<<endl<<"Alfabetiska tecken:"<<letters<<endl
  <<"Siffertecken......:"<<num<<endl<<"Vita tecken.......:"<<blank<<endl<<endl;
  cin.ignore(1000,'\n');

//////////

  cout<<"Del 3: Ordhantering"<<endl<<"Mata in en text:"<<endl<<endl;
  num = 0;

    while(cin>>str){

        no_text_buffer = false;

        sum = sum + str.size();

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

      average = (static_cast<double>(sum) / static_cast<double>(num));


      cout<<"Texten innehöll "<<num<<" ord."<<endl;
      cout<<"Det kortaste ordet var \""<<short_word<<"\" med "<<short_word.size()<<" tecken."<<endl;
      cout<<"Det längsta ordet var \""<<long_word<<"\" med "<<long_word.size()<<" tecken."<<endl;
      cout<<"Medelordlängden var "<<fixed<<setw(1)<<setprecision(1)<<average<<" tecken."<<endl;
      return 0;
    }
 }
/////////////////////////////////////////////////////////////





#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>

  using namespace std;

//Main///////////////
  
int main(){

///Variable//////////

    int start;
    int end;
    int letters = 0;
    int num = 0;
    int blank = 0;
    double sum = 0;
    double kel;
    double far;
    double rem;
    double average;
    char cha;
    bool no_text_buffer = true;
    string str;
    string short_word;
    string long_word;
    

//////////

    cout<<"Del 1: Temperaturtabell"<<endl;    
     // while(true){
        
        cout<<"Ange startvärde: ";
        
        do{
          cin>>start;
          if(start < -273.15){
            cout<<"Felaktigt startvärde!"<<endl;
            }
        } 
        while (start < -273.15);

      
  
      do{
        cout<<"Ange slutvärde: ";
        cin>>end;

          if(start > end){
            cout<<"Felaktigt slutvärde!"<<endl;
            cin.ignore(1000,'\n');
                    }
  
        kel = start + 273.15;
        far = (start * 1.8) + 32;
        rem = start * 0.8;

      }while(start > end);


    cout<<"Celsius   Kelvin   Fahrenheit   Reaumur"<<endl
    <<"---------------------------------------"<<endl;
        while(start<=end){
            cout.width(7);
            cout<<start;
            cout.width(9);
            cout<<fixed<<setprecision(2)<<kel;
            cout.width(13);
            cout<<fixed<<setprecision(2)<<far;
            cout.width(10);
            cout<<fixed<<setprecision(2)<<rem<<endl;

            start++;
            kel = start + 273.15;
            far = (start * 1.8) + 32;
            rem = start * 0.8;
        }
    cout<<"---------------------------------------"<<endl<<endl;
    cin.ignore(1000,'\n');

//////////

  cout<<"Del 2: Teckenhantering"<<endl;
    for(int i{}; i < 10; i++){
      cin.get(cha);
        if(isdigit(cha)){
          num++;
        }
        else if(isalpha(cha)){
          letters++;
        }
        else if(isspace(cha)){
          blank++;
        }
    }

  cout<<"Texten innehöll:"<<endl<<"Alfabetiska tecken:"<<letters<<endl
  <<"Siffertecken......:"<<num<<endl<<"Vita tecken.......:"<<blank<<endl<<endl;
  cin.ignore(1000,'\n');

//////////

  cout<<"Del 3: Ordhantering"<<endl<<"Mata in en text:"<<endl<<endl;
  num = 0;

    while(cin>>str){

        ///no_text_buffer = false;

        sum = sum + str.size();

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
    if(num == 0){
      cout<<"Inga ord matades in."<<endl;
    }
    else{

      average = (static_cast<double>(sum) / static_cast<double>(num));


      cout<<"Texten innehöll "<<num<<" ord."<<endl;
      cout<<"Det kortaste ordet var \""<<short_word<<"\" med "<<short_word.size()<<" tecken."<<endl;
      cout<<"Det längsta ordet var \""<<long_word<<"\" med "<<long_word.size()<<" tecken."<<endl;
      cout<<"Medelordlängden var "<<fixed<<setw(1)<<setprecision(1)<<average<<" tecken."<<endl;
    }
    return 0;
 }
 
