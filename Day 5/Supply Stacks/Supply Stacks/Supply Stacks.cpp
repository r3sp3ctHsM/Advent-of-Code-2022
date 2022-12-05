// Supply Stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string myText;
ifstream myCrates("..\\Resources\\Crates.txt");

const int stackSize = 9;

vector<char> stack[stackSize]; //Array of vectors
vector<int> command;

void printStack()
{
    for (int i = 0; i < 3; i++)
    {
        for (auto it = stack[i].begin(); it != stack[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void doCommands(int amount, int start, int end)
{
    start -= 1;
    end -= 1;
    //part 1
    /*for (int i = 0; i < amount; i++)
    {
        stack[end].push_back(stack[start].back());
        stack[start].pop_back();
    }*/

    //part 2
    vector<char> crane;
    for (int i = 0; i < amount; i++)
    {
        crane.push_back(stack[start].back());
        stack[start].pop_back();
    }
    for (int i = 0; i < amount; i++)
    {
        stack[end].push_back(crane.back());
        crane.pop_back();
    }
    printStack();
}

void pushBackDigit(string text)
{
    bool isDigit = false;
    for (char c : text)
    {
        if (isdigit(c))
        {
            isDigit = true;
        }
        else
        {
            isDigit = false;
        }
    }
    if (isDigit)
    {
        command.push_back(stoi(text));
    }
}

int main()
{
    //std::cout << "Hello World!\n";

    bool isCommands = false;
    while (getline(myCrates, myText))
    {
        if (myText == "")
        {
            isCommands = true;
        }
        if (!isCommands)
        {
            for (int i = 0; i < myText.size(); i = i + 4)
            {
                if ((myText.at(i + 1) != ' ') && (!isdigit(myText.at(i + 1))))
                {
                    stack[i / 4].push_back(myText.at(i + 1));
                }
            }
        } 
        else
        {
            string delimiter = " ";
            size_t pos = 0;
            string token;
            while ((pos = myText.find(delimiter)) != string::npos)
            {               
                token = myText.substr(0, pos);
                pushBackDigit(token);
                myText.erase(0, pos + delimiter.length());
            }
            pushBackDigit(myText);
        }
    }

    for (int i = 0; i < stackSize; i++)
    {
        reverse(stack[i].begin(), stack[i].end());
    }

    printStack();

    for (int i = 0; i < command.size(); i = i + 3)
    {
        cout << command.at(i) << " " << command.at(i + 1) << " " << command.at(i + 2) << endl;
        doCommands(command.at(i), command.at(i + 1), command.at(i + 2));
    }

    cout << endl;

    for (int i = 0; i < stackSize; i++)
    {
        cout << stack[i].back() << " ";
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
