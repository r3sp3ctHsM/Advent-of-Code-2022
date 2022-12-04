// Calorie Counting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool mySort(int i, int j) { return (i > j); }

int main()
{
    //std::cout << "Hello World!\n";

    std::string myText;
    std::ifstream myCalories("..\\Resources\\Calories.txt");

    std::vector<int> snacks;
    std::vector<std::vector<int>> elf;

    while (std::getline(myCalories, myText))
    {
        if (myText != "")
        {
            snacks.push_back(std::stoi(myText));
        }
        else
        {
            elf.push_back(snacks);
            snacks.clear();
        }
    }

    std::vector<int> totals;

    for (std::vector<int> e : elf)
    {
        int total = 0;
        for (int i : e)
        {
            total += i;
        }
        totals.push_back(total);
    }
   
    std::sort(totals.begin(), totals.end(), mySort);

    std::cout << totals.at(0) << " " << totals.at(1) << " " << totals.at(2) << std::endl;

    int result = totals.at(0) + totals.at(1) + totals.at(2);

    std::cout << result << std::endl;
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
