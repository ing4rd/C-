// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
//header_guard
# ifndef REGISTER_HANDLING_H
# define REGISTER_HANDLING_H

#include <vector>
#include <string>

#include  "hero_handling.h"

using Register_type = std::vector<Hero_type>;

void search(Register_type & heroes,
	    Register_type & matches,
	    std::string const & file_name);
void add(Register_type & heroes,
	 std::string const & file_name);

# endif
