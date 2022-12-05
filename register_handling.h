// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
//header_guard
# ifndef REGISTER_HANDLING_H
# define REGISTER_HANDLING_H

#include <vector>
#include <string>

#include  "hero_handling.h"

using register_type = std::vector<hero_type>;

    void search(register_type & heroes,
                register_type & matches,
                std::string const & file_name);
    void add(register_type & heroes,
             std::string const & file_name);

# endif
