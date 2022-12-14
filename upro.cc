// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

////////////////////////

int sub_fact(int const item){
      
  int I {item};

  if (I == 0){
    return 1;
  }
  else{ 
    return I * sub_fact(I-1);
  }
} 

////////////////////////

string Sub_Mult(string const & item,
		int    const   value){
  string res{};
  for (int i {0}; i < value; i++ )
    {
      res += item;
    }
  return res;
  
}

//////////////////////////

void Sub_swap(int&     a,
	      double&  b)
{
  double c{};

  c = a;
  a = static_cast<int>(ceil(b));
  b = c; 
}


////////////////////////

void Sub_calc_string(string const & text_1,
		     string  const & text_2,
		     int           & total_length,
		     double        & mean_length){
   
  total_length = text_1.size() + text_2.size();
  mean_length  = (static_cast<double>(total_length) / 2.0);
}

////////////////////////

void Menu_Selection(int & selection){

  bool out_of_range;

  do{
    out_of_range = false;
    cout<<"1. Beräkna N-fakultet."<<endl
	<<"2. Multiplicera en sträng."<<endl
	<<"3. Byta värden på ett heltal och ett flyttal."<<endl
	<<"4. Beräkna totala längden samt medellängden på två strängar."<<endl
	<<"5. Avsluta programmet."<<endl
	<<"Val: ";
    cin>>selection;
    if(selection > 5 || selection < 1){
      cout<<"Fel val!"<<endl;
      out_of_range = true;
      cin.ignore(1000,'\n');
    }
  }while(out_of_range);
}
    
/////////////////////////

void choice_1(int const selection){

  int numb{};
  string str{};
  int N{};

  if(selection == 1){
    cout<<"Mata in ett heltal: ";
    cin >> N;
    cout<<"Fakulteten av "<< N <<" är "<<sub_fact(N)<<endl;
  }

  else if(selection == 2){

    cout<<"Mata in en text och ett heltal: ";
    cin >> str >>  numb  ;
    cout <<"Den multiplicerade texten är ";
    cout << Sub_Mult(str, numb);
    //Sub_Mult(str,numb);
    cout<<endl;
  } 

}

///////////////////

void choice_2(int const selection){

  int a{};
  double b{};
  int total_length{};
  double mean_length{};
  string text_1{};
  string text_2{};



  if(selection == 3){
    cout<<"Mata in ett heltal och ett flyttal: ";
    cin >>  a >>  b;
    Sub_swap(a,b);
    cout<<"Heltalets värde är nu "<<  a <<endl
	<<"Flyttalets värde är nu "<<fixed<<setw(1)<<setprecision(1)<<  b <<endl;
  }

  else if(selection == 4){
    cout<<"Mata in två ord: ";
    cin >>  text_1;
    cin >>  text_2;
    Sub_calc_string(text_1,
		    text_2,
		    total_length,
		    mean_length);
    cout<<"Totallängd: "<<  total_length  <<endl
	<<"Medellängd: "<<fixed<<setw(2)<<setprecision(1)<< mean_length <<endl;
  }
}

//Main///////////////////

int main(){

  int selection{};

  ///////////

  cout<<"Välkommen till huvudmenyn!"<<endl;
  do{
    Menu_Selection(selection);

    if(selection == 1 || selection == 2){
      choice_1(selection);
    }

    else if(selection == 3 || selection == 4){
      choice_2(selection);
    }

  }while(selection != 5);

  cout<<"Ha en bra dag!"<<endl;

  return 0;
}

