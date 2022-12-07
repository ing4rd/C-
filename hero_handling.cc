// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>

# include "register_handling.h"
# include "hero_handling.h"

using namespace std;

/////////////

bool compare_matches(Hero_type const & item,
		     int       const   compare){
        
  for (int i = 0; i < item.intrest.size(); i++){
    if(compare == item.intrest.at(i)){
      return true;
    }
  }
  return false;
}

///////////

void print_to_stream(Hero_type const & item,
		     ostream         & write_to){

  write_to<<" "<<item.name<<" "<<item.bithyear
	  <<" "<<item.weight<<" "<<item.hair_color;

  for( int i = 0; i < item.intrest.size();i++){
    write_to<<" "<<item.intrest.at(i);
  }

  write_to<<endl;
}

//////////

bool sort_by_name(Hero_type const & a,
		  Hero_type const & b){

  return a.name[0] < b.name[0];

}

///////////

void feed_struct(Hero_type & hero){

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
  stringstream ss{str};
  while(ss >> like){
    hero.intrest.insert(hero.intrest.begin(),like);
  }
  sort(hero.intrest.begin(), hero.intrest.end());
       
}

////////////

void print_hero(Hero_type const & item){

  double weight_as_flo = stod(item.weight);

  cout.width(11); 
  cout<<left<<item.name;
  cout.width(12); 
  cout<<left<<item.bithyear;
  cout.width(8); 
  cout<<fixed<<setprecision(2)<<weight_as_flo;
  cout.width(11); 
  cout<<item.hair_color;
  cout.width(1);
  cout<<" ";
                
  for( int i = 0; i < item.intrest.size();i++)
    {
      cout<<right<<setw(3)<<item.intrest.at(i);
    }
  cout<<endl;
}



 
