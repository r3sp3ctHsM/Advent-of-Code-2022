// Rucksack Reorganization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    //std::cout << "Hello World!\n";

    std::string myText;
    std::ifstream MyBackpack("..\\Resources\\Backpack.txt");

    std::vector<std::string> comp1, comp2, comp3;
    int count = 0;

    while (std::getline(MyBackpack, myText))
    {
        //std::cout << myText << std::endl;
        /*int size = myText.size();
        int count = 0;
        std::string result1 = "";
        std::string result2 = "";
        for (char c : myText)
        {       
            if (count < size / 2)
            {
                result1 += c;
                count++;
            }
            else
            {
                result2 += c;
                count++;
            }
        }
        comp1.push_back(result1);
        comp2.push_back(result2);*/

        switch (count)
        {
            case 0:
                comp1.push_back(myText);
                count++;
                break;
            case 1:
                comp2.push_back(myText);
                count++;
                break;
            case 2:
                comp3.push_back(myText);
                count = 0;
                break;
        }
    
    }

    MyBackpack.close();

    int sum = 0;
    for (int i = 0; i < comp1.size(); i++)
    {
        /*std::cout << comp1.at(i) << std::endl;
        std::cout << comp2.at(i) << std::endl;
        std::cout << comp3.at(i) << std::endl;*/

        bool isSame = false;
        for (char c1 : comp1.at(i))
        {
            for (char c2 : comp2.at(i))
            {
                for (char c3 : comp3.at(i))
                {
                    if (c1 == c2 && c2 == c3 && isSame == false)
                    {
                        isSame = true;
                        int result = int(c1);
                        if (isupper(c1))
                        {
                            result = result + (26 - 64);
                            sum += result;
                        }
                        else if (islower(c1))
                        {
                            result = result - 96;
                            sum += result;
                        }
                    }
                }
                
            }
        }
        std::cout << sum << std::endl;
    }
 
       
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
