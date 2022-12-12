#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
//======================================
int calc_first_border(string const outer,
                      string const inner,
                      int const width)
{
    string second_row;
    double sec_row;

    second_row = outer;

    for (int i{}; i < width; i++)
    {
        second_row += inner;
    }
    sec_row = second_row.size();

    return ceil(second_row.size() / outer.size());
}
//======================================
void read(string const &inner,
          string const &outer,
          int const height,
          int const width)
{
    cin >> border_word >> inner_word;
    cout << "Enter dimensions: ";
    cin >> height >> width;
}

//======================================
void print(string const &inner,
           string const &outer,
           int const height,
           int const width)
{
    int temp{width};

    for (int i{}; i < calc_first_border(outer, inner, width); i++)
    {
        cout << outer;
    }
    cout << endl;

    for (int i{}; i < height; i++)
    {
        cout << outer;
        for (int j{}; j < temp; j++)
        {
            cout << inner;
            temp--;
        }
        cout << endl;
    }
}

//======================================
int main()
{

    string inner_word, border_word;
    int height, width;

    read(inner_word,
         border_word,
         height,
         width);

    print(inner_word,
          border_word,
          height,
          width);
}
