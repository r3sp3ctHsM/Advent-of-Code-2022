// Camp Cleanup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    //std::cout << "Hello World!\n";

    std::string myText;
    std::ifstream myPairs("..\\Resources\\Pairs.txt");
    std::string delimeter1 = ",";
    std::string delimeter2 = "-";
    std::string input;
    std::string output;
    size_t pos = 0;
    size_t pos1 = 0;

    std::vector<int> elf1, elf2;
    std::vector<std::vector<int>> pair;

    bool first = true;

    int result = 0;
    int i = 0;

    while (std::getline(myPairs, myText))
    {
        while ((pos = myText.find(delimeter1)) != std::string::npos)
        {
            input = myText.substr(0, pos);
            myText.erase(0, pos + delimeter1.length());
            //std::cout << input << std::endl;
        }
        //std::cout << myText << std::endl;

        while ((pos1 = input.find(delimeter2)) != std::string::npos)
        {
            output = input.substr(0, pos1);
            elf1.push_back(std::stoi(output));
            input.erase(0, pos1 + delimeter2.length());
            std::cout << output << " ";
        }
        std::cout << input << " ";
        elf1.push_back(std::stoi(input));

        while ((pos1 = myText.find(delimeter2)) != std::string::npos)
        {
            output = myText.substr(0, pos1);
            elf2.push_back(std::stoi(output));
            myText.erase(0, pos1 + delimeter2.length());
            std::cout << output << " ";
        }
        std::cout << myText << std::endl;
        elf2.push_back(std::stoi(myText));

        //THIS IS DUMB DUMB COS I THOUGHT MY ANSWER WAS WRONG THE WHOLE TIME AND REDID THIS EQUATION MULTIPLE TIMES AND ITS REDUNDANT IN PARTS ALL BECAUSE I MISTYPED THE ANSWER THE FIRST TIME
        if (((elf1.at(i) <= elf2.at(i)) && (elf1.at(i + 1) >= elf2.at(i + 1))) || ((elf2.at(i) <= elf1.at(i)) && (elf2.at(i + 1) >= elf1.at(i + 1))) 
            || ((elf1.at(i) <= elf2.at(i)) && (elf1.at(i + 1) >= (elf2.at(i))))
            || ((elf2.at(i) <= elf1.at(i)) && (elf2.at(i + 1) >= (elf1.at(i)))))
        {
            result++;
        }
        i += 2;
    }

    std::cout << result << std::endl;

    myPairs.close();
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
