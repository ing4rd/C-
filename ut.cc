// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>

  using namespace std;
int main(){

  int num;
  double flo;
  char cha;
  string str;

  /////////////////////

  cout<<"Skriv in ett heltal: ";
  cin>>num;
  cout<<"Du skrev in heltalet: "<<num<<endl<<endl;

  cout<<"Skriv in fem heltal: ";
  cin>>num; 
  cout<<"Du skrev in heltalen: ";
  cout << num << " ";
  cin>>num;
  cout<<num<<" ";
  cin>>num;
  cout<<num<<" ";
  cin>>num;
  cout<<num<<" ";
  cin>>num;
  cout<<num<<endl<<endl;;
 
  cout<<"Skriv in ett flyttal: ";
  cin>>flo;
  cout<<"Du skrev in flyttalet: "<<setw(0)<<setprecision(3)<<fixed<<flo<<endl<<endl;


  cout<<"Skriv in ett heltal och ett flyttal: ";
  cin>>num>>flo;
  cout<<"Du skrev in heltalet:"<<fixed<<setw(10)<<num<<endl;
  cout<<"Du skrev in flyttalet:"<<fixed<<setw(9)<<setprecision(4)<<flo<<endl<<endl;


  cout<<"Skriv in ett flyttal och ett heltal: ";
  cin>>flo>>num;    
  cout<<"Du skrev in heltalet:"<<setfill('-')<<fixed<<setw(10)<<num<<endl;
  cout<<"Du skrev in flyttalet:"<<setfill('-')<<fixed<<setw(9)<<setprecision(4)<<flo<<endl<<endl;


  cout<<"Skriv in ett tecken: ";
  cin>>cha;
  cout<<"Du skrev in tecknet: "<<cha<<endl<<endl;


  cout<<"Skriv in ett ord: ";
  cin>>str;
  cout<<"Du skrev in ordet: "<<str<<endl<<endl;


  cout<<"Skriv in ett heltal och ett ord: ";
  cin>>num>>str;    
  cout<<"Du skrev in heltalet |" <<num<<"| och ordet |"<<str<<"|."<<endl<<endl;


  cout<<"Skriv in ett tecken och ett ord: ";
  cin>>cha>>str;
  cout<<"Du skrev in \"" <<str<<"\" och \""<<cha<<"\"."<<endl<<endl;  


  cout<<"Skriv in ett ord och ett tecken: ";
  cin>>str>>cha;
  cout<<"Du skrev in \"" <<str<<"\" och \""<<cha<<"\"."<<endl<<endl;  

    
  cin.ignore(1000, '\n');
  cout<<"Skriv in en textrad:";
  getline(cin,str);
  cout<<"Du skrev in \""<<str<<"\"."<<endl<<endl;

  cout<<"Skriv in en till rad text: ";
  getline(cin,str);
  cout<<"Du skrev in \""<<str<<"\"."<<endl<<endl;


  cout<<"Skriv in en rad med tre ord: ";
  cin>>str;
  cout<<"Du skrev in: \""<<str;
  cin>>str;
  cout<<"\", \""<<str;
  cin>>str;
  cout<<"\" och \""<<str<<"\"."<<endl;

}
