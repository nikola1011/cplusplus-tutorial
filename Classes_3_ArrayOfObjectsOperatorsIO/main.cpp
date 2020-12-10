#include <iostream>
#include <fstream>
#include "Player.h"
#include "FudbalClub.h"

using namespace std;

int main()
{
    FudbalClub fc1;

    ifstream input;
    input.open("players.txt");

    input >> fc1;
    cout << fc1 << endl;
    input.close();

    ofstream output;
    output.open("sorted_players.txt");
    fc1.sortPlayersByPay();
    cout << "Sorted:\n" << fc1 << endl;
    output << fc1;
}