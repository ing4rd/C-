//header_guard
# ifndef REGISTER_HANDLING_H
# define REGISTER_HANDLING_H

#include  "hero_handling.h"
#include <vector>


using register_type = std::vector<hero_type>;

    void get_register_1(register_type & item);
    void add_to_register_1(register_type & item);

# endif