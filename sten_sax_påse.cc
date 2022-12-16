#include <iostream>
#include <string>
//============================

bool deciding_winner(int &AI,
                     int &player,
                     bool &winner)
{
    if (AI == player)
    {
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
    int rnd_num{rand()};
    string temp;

    do
    {
        bool bad_value{false};
        switch (rnd_num)
        {
        case rnd_num <= (RAND_MAX / 3):
            AI = 1;
            break;

        case rnd_num >= ((RAND_MAX / 3) * 2):
            AI = 2;

        default:
            AI = 3;
            break;
        }

        cin >> temp;
        if (temp == 'STEN' || temp == "sten")
        {
            player = 1;
        }
        else if (temp == "sax")
        {
            player == 2;
        }
        else if (temp == "påse")
        {
            player == 3;
        }
        else
        {
            bad_value = true;
            cin.ignore(1000, '\n');
        }

    } while (bad_value)
}

//============================

void play()
{

    int AI;
    int player;
    bool winner;

    do
    {
        for (int i{}; i < 3; i++)
        {
            wait();
            cout << i;
        }
        seting_values(AI, player);

    } while (deciding_winner(AI, player, winner));

    cout << AI << "      " << player << ;
    if (winner)
    {
        cout << "Du vann, gratulerar!"
    }
    else
    {
        cout << "Du förlora, attans!";
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

        else
        {
            cout << "Du matande in ett felaktigt värde!" << endl;
        }
    } while (cha == 'e');

    cout << "Tack för att du spelade!";

    return 0;
}
