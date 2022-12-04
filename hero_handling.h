// antin019: Samarbetat med omiaz320, Omid Azimi, samma program
//header_guard
# ifndef HERO_HANDLING_H
# define HERO_HANDLING_H

# include <string>
# include <vector>
# include <fstream>

//private

    struct hero_type
    {
        std:: string name;
        std:: string bithyear;
        std:: string weight;
        std:: string hair_color;
        std:: vector<int> intrest;
    };
using register_type = std::vector<hero_type>;

    bool operator ==(hero_type const a,
                     hero_type const b);
    bool compare_matches(hero_type const item,
                         int const compare);
    void print_to_stream(hero_type const item,
                         std::ostream & write_to);
    void print_hero(hero_type const item);
    void feed_struct(hero_type & hero);
    bool sort_by_name(hero_type const a,
                      hero_type const b);

# endif //header guard /HERO_HANDLING.H

    
