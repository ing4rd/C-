#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;
//============================

string print_string(int const value){

    if(value == 1){
        return "STEN";
    }
    else if(value == 2){
        return "SAX";
    }
    else if(value == 3){
        return "PÅSE";
    }
    else{
        return "ANNAT";
    }
}

//============================

bool deciding_winner(int &AI,
                     int &player,
                     bool &winner)
{
    if (AI == player|| player == 4)
    {
        cout << "Datorn valde: " << print_string(AI) << endl << "Du valde: "<< print_string(player) << '\n' <<endl;
        return true;
    }
    else if ((AI == 1 && player != 3) || (AI == 2 && player != 1) || (AI == 3 && player != 2))
    {
        winner = false;
        return false;
    }
    else
    {
        winner = true;
        return false;
    }
}

//============================

void seting_values(int &AI,
                   int &player)

{
    bool bad_value{false};
    int const rnd_num{rand()};
    string temp;


        if(rnd_num < (RAND_MAX / 3)){
            AI = 1;
        }
        else if(rnd_num > ((RAND_MAX / 3)*2)){
            AI = 2;
        }
        else{
            AI = 3;
        }

        cin >> temp;
        if (temp == "sten")
        {
            player = 1;
        }
        else if (temp == "sax")
        {
            player = 2;
        }
        else if (temp == "påse")
        {
            player = 3;
        }
        else
        {
            player = 4;
        }

}

//============================

void play()
{

    int AI;
    int player;
    bool winner;
    vector<string> ssp{"STEN","SAX","PÅSE"};

    do
    {
        for (int i{}; i < 3; i++)
        {
            sleep(2);
            cout << ssp.at(i)<<'\n' <<endl;
        }
        seting_values(AI, player);
        cin.ignore(1000, '\n');

    } while (deciding_winner(AI, player, winner));

    cout << "Datorn valde: " << print_string(AI) << endl << "Du valde: "<< print_string(player) << '\n' <<endl;
    if (winner)
    {
        cout << "Du vann, gratulerar!"<< endl;
    }
    else
    {
        cout << "Du förlora, attans!"<< endl;
    }
}
//=============================
int main()
{
    char cha;

    do
    {
        cout << "Tryck på 's' för att spela eller 'e' för att avsluta: " << endl;
        cin >> cha;

        if (cha == 's')
        {
            play();
        }

        else if(cha != 'e')
        {
            cout << "Du matande in ett felaktigt värde!" << endl;
        }
    } while (cha != 'e');

    cout << "Tack för att du spelade!";

    return 0;
}
