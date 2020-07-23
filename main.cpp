/*************************************************************************
 * AUTHOR           :  David Shin
 * Project          :  Text Adventure
 ************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

/*************************************************************************
* Project - Text Adventure
* _________________________________________________________________________
* This program takes the user's input for their name, the monster name,
* and directions and simulates a text adventure.
* _________________________________________________________________________
* INPUT:
*    name         :  Asks for their name
*    monster      :  Asks for the monster's name
*    door         :  Asks for the door in which the user wants to enter
___________________________________________________________________________
*************************************************************************/
void monsterRoom(int, int);     //  Monster room function prototype
void genieRoom(int, int);       //  Genie room function prototype
void pictureRoom();             //  Picture room function prototype
void drawPicture();             //  Draw picture function prototype

int main()
{
    int banana;         //  A constant for the number of bananas
    int orange;         //  A constant for the number of oranges
    int align;          //  A number used to generate different alignments
    string name;        //  INPUT - Grabs user's name
    string monster;     //  INPUT - Grabs user's choice of direction
    char door;

    srand(500);         //  Random number generator

    banana = 5;         //  Initializes banana
    orange = 3;         //  Initializes oranges

    cout << "Please enter your name: \n";
    cin >> name;

    cout << "Name your scariest monster: \n";
    cin >> monster;


    align = rand()%2;
    cout << name << ", you are in a room with 4 doors.\n\n"
         << "You are carrying " << banana << " bananas and "
         << orange << " oranges.\n";

    cout << "Pick a door to enter by typing the direction it is in "
         << "(N/E/S/W): \n";
    cin >> door;

    do
    {
        if(door == 'N' || door == 'S' || door == 'W' || door == 'E')
        {
            if(align == 0)
            {
                if(door == 'N')
                {
                    cout << endl;
                    cout << "WATCH OUT!!!" << endl << monster;

                    monsterRoom(banana, orange);
                    banana = 0;
                    orange = 0;
                }
                else if(door == 'S')
                {
                    genieRoom(banana, orange);
                    banana += 2;
                    orange += 1;
                }
                else if(door == 'W')
                {
                    door = '0';
                }
                else if(door == 'E')
                {
                    pictureRoom();
                }
            }
            else if (align == 1)
            {
                if(door == 'N')
                {
                   door = '0';
                }
                else if(door == 'S')
                {
                    cout << endl;
                    cout << "WATCH OUT!!!" << endl << monster;

                    monsterRoom(banana, orange);
                    banana = 0;
                    orange = 0;
                }
                else if(door == 'W')
                {
                    pictureRoom();
                }
                else if(door == 'E')
                {
                    genieRoom(banana, orange);
                    banana += 2;
                    orange += 1;
                }
            }
            if(door != '0')
            {
                cout << name << ", you are in a room with 4 doors.\n\n"
                     << "You are carrying " << banana << " bananas and "
                     << orange << " oranges.\n";

                cout << "Pick a door to enter by typing the direction it "
                        "is in (N/E/S/W): \n";
                cin >> door;
                align = rand()%2;
            }

        }
        else if(door != 'N' || door != 'S' || door != 'W' || door != 'E')
        {
            cout << "Pick a door to enter by typing the direction it "
                 << "is in (N/E/S/W): \n";
            cin >> door;

        }
    }
    while(door != '0');
    cout << endl;
    cout << "You found the exit!\n";
    cout << "Your score is " << banana + orange << "(" << banana
         << " bananas and " << orange << " oranges).\n";
    cout << "Bye bye!!!\n";
}
void monsterRoom(int b, int o)
{
    cout << " attacks you and steals all of your bananas and "
         << "oranges.\n";
}
void genieRoom(int b, int o)
{
    cout << endl;
    cout << "!!Poof!! ";
    cout << "A Genie pops out and grants you 2 bananas and 1 orange.\n";
}
void pictureRoom()
{
    cout << endl;
    cout << "You found a picture!\n";
    drawPicture();
}
void drawPicture()
{
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}
