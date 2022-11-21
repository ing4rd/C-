-- antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>

  using namespace std;
int main(){

    int start;
    int slut;
    char cha;
    string str;
    string short;
    string long;
    int letters = 0;
    int num = 0;
    int blank = 0;

///cel_kel/////////////

    cel_kel(int const item){
        
        double temp;

        temp = item;
        return temp + 273.15;
    }
    
///cel_far////////////

    cel_far(int const item){

        double temp;

        temp = item;
        return (temp * 1.8) + 32;
    }

///cel_rem/////////////

    cel_rem(int const item){

        double temp;

        temp = item;
        return temp * 0.8;
    }

///average////////////

    average(int const start, int const slut){
      double temp;
      temp = (start+slut)/2;
      return temp;
    }


///////////////////////
    cout<<"Del 1: Temperaturtabell"<<endl;    
    while(start > slut){
    <<"Ange startvärde: ";
    cin>>start;
    cout<<"Ange slutvärde: "
    cin>>slut;
    if(start < slut){
        cout<<"Felaktigt slutvärde!"<<endl;
    }
    }

    cout<<"Celsius Kelvin Fahrenheit Reaumur"<<endl;
    cout<<"---------------------------------------"<<endl;
        for(int i; start = slut; start++){
            cout<<start<<cel_kel(start)<<cel_far(start)<<cel_rem(start)<<endl;
        }

  cout<<"Del 2: Teckenhantering"<<endl;
    for(int i; i = 0; i < 11; i++){
    cin.get(cha);
      if(isdigit(cha)){
        num = num +1;
      }
      else if(isalpha(cha)){
        letters = letters + 1;
      }
      else if(isspace(cha)){
        blank = blank + 1;
      }

    cin.ignore(10,'\n');

  cout<<"Texten innehöll:"<<endl<<"Alfabetiska tecken:"<<letters<<endl;
  cout<<"Siffertecken......:"<<num<<endl<<"Vita tecken.......:"<<blank<<endl;


  cout<<"Del 3: Ordhantering"<<endl<<"Mata in en text:"<<endl;
  cin.ignore(1000,'\n');
  getline(cin,str);



  cout<<"Texten innehöll "<<num<<" ord."<<endl;
  cout<<"Det kortaste ordet var "<<short<<" med "<<start<<" tecken."<<endl;
  cout<<"Det längsta ordet var "<<long<<" med "<<slut<<" tecken."<<endl;
  cout<<"Medelordlängden var "<<average(start,slut)<<" tecken."<<endl;



    }
