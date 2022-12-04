// Rock Paper Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    //std::cout << "Hello World!\n";

    std::string myText;
    std::ifstream MyStrats("..\\Resources\\Strats.txt");

    std::vector<char> opp, you;

    while (std::getline(MyStrats, myText))
    {
        int count = 0;
        for (char c : myText)
        {
            if (count == 0)
            {
                opp.push_back(c);
            }
            if (count == 2)
            {
                you.push_back(c);
            }
            count++;
        }
    }

    MyStrats.close();

    int score = 0;

    for (int i = 0; i < opp.size(); i++)
    {
        //std::cout << opp.at(i) << std::endl;
        //std::cout << you.at(i) << std::endl;

        /*      
        * A = Rock = 1     
        * B = Paper = 2     
        * C = Scissors = 3     
        * X = Lose = 0      
        * Y = Draw = 3     
        * Z = Win = 6      
        * */

        switch (opp.at(i))
        {
        case 'A':
            switch (you.at(i))
            {
            case 'X':
                score += 3;
                break;
            case 'Y':
                score += 4;
                break;
            case 'Z':
                score += 8;
                break;
            }
            break;
        case 'B':
            switch (you.at(i))
            {
            case 'X':
                score += 1;
                break;
            case 'Y':
                score += 5;
                break;
            case 'Z':
                score += 9;
                break;
            }
            break;
        case 'C':
            switch (you.at(i))
            {
            case 'X':
                score += 2;
                break;
            case 'Y':
                score += 6;
                break;
            case 'Z':
                score += 7;
                break;
            }
            break;
        }
    }

    std::cout << score << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
