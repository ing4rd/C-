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
///average///////////

    double average(int sum_of_all,
                   int amount){

        return static_cast<double>(sum_of_all) / static_cast<double>(amount);
    }
///add///////////////

    void add(string item,
             double& sum){

      sum = sum + item.size();
    }
//Main///////////////
  
int main(){

///Variable//////////

    int start;
    int end;
    int letters = 0;
    int num = 0;
    int blank = 0;
    double sum = 0;
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


    cout<<"Celsius Kelvin Fahrenheit Reaumur"<<endl
    <<"---------------------------------------"<<endl;
        while(start<=end){
            cout<<setw(7)<<start<<fixed<<setw(7)<<setprecision(2)<<cel_kel(start)
            <<fixed<<setw(11)<<setprecision(2)<<cel_far(start)<<fixed<<setw(8)
            <<setprecision(2)<<cel_rem(start)<<endl;
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
  cin.ignore(1000,'\n');

  cout<<"Del 3: Ordhantering"<<endl<<"Mata in en text:"<<endl;
  num = 0;

    while(cin>>str){

        no_text_buffer = false;
        add(str,sum);

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
    cout<<"Det kortaste ordet var \""<<short_word<<"\" med "<<short_word.size()<<" tecken."<<endl;
    cout<<"Det längsta ordet var \""<<long_word<<"\" med "<<long_word.size()<<" tecken."<<endl;
    cout<<"Medelordlängden var "<<fixed<<setw(1)<<setprecision(1)<<average(sum,num)<<" tecken."<<endl;
    }
 }
