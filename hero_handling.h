//header_guard
# ifndef HERO_HANDLING_H
# define HERO_HANDLING_H

# include <string>
# include <vector>

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

    void add(register_type & heroes);
    void search(register_type & heroes,
                register_type & matches);

# endif //header guard /HERO_HANDLING.H

    