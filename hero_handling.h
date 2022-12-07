// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
//header_guard
# ifndef HERO_HANDLING_H
# define HERO_HANDLING_H

# include <string>
# include <vector>
# include <fstream>

//private

struct Hero_type
{
  std:: string name;
  std:: string bithyear;
  std:: string weight;
  std:: string hair_color;
  std:: vector<int> intrest;
};

bool operator ==(Hero_type const & a,
		 Hero_type const & b);
bool compare_matches(Hero_type const & item,
		     int const compare);
void print_to_stream(Hero_type const & item,
		     std::ostream & write_to);
void print_hero(Hero_type const & item);
void feed_struct(Hero_type & hero);
bool sort_by_name(Hero_type const & a,
		  Hero_type const & b);

# endif //header guard /HERO_HANDLING.H

    
