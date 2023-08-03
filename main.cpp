#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

void printTitle();
void printMan(int);
void printSentence(string sentence, string& guess, char alpha);
bool checkWin(string, string);
bool guessedAlready(char, vector<char>);
void clearScreen();

int main()
{
    string sentence = "channel"; //The hidden answer
    string guess = "";
    vector<char> userguesses;
    char temp;
    char userguess;
    int miss = 0;


    //Initialize the users guess
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isspace(sentence[i]))
        {
            guess += ' ';
        }
        else
        {
            guess += '_';
        }
    }

    printTitle();
    
    while (miss < 6)
    {
        clearScreen();
        printMan(miss);
        cout << endl;
        cout << guess << endl;

        cout << "Enter Guess [a ~ z]: ";
        cin >> userguess;
        cout << endl;

        while (guessedAlready(userguess, userguesses))
        {
            clearScreen();
            printMan(miss);
            cout << endl;
            cout << guess;

            cout << "   '"<< userguess << "'" << " guessed already." << endl;
            cout << "Enter Guess [a ~ z]: ";
            cin >> userguess;
            cout << endl;
        }

        userguesses.push_back(userguess);

        bool matchfound = false;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (userguess == sentence[i])
            {
                temp = userguess;
                matchfound = true;
            }
            else
            {
                temp = '\0';
            }

            if (temp == sentence[i])
            {
                guess[i] = temp;
            }
        }


        if (!matchfound)
        {
            miss++;
        }

        if (checkWin(sentence, guess))
        {
            clearScreen();
            cout << "\"" << sentence << "\"" << " is correct!!" << endl;
            cout << "YOU WIN" << endl;
            return 0;
        }
        cout << endl;
    }

    clearScreen();
    printMan(miss);
    cout << endl;
    cout << guess << endl;
    cout << endl;
    cout << "YOU LOSE!!" << endl;
    cout << "Correct Answer: " << sentence << endl;
}

void printTitle()
{
    clearScreen();
    cout << "*************************" << endl;
    cout << "*        HANGMAN        *" << endl;
    cout << "* <Press Enter to Play> *"<< endl;
    cout << "*************************" << endl;
    cin.ignore();
    clearScreen();
}

void printMan(int miss)
{
    switch (miss)
    {
        case 1:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 2:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "|  |" << endl;
            cout << "|" << endl;
            break;
        case 3:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "| /|" << endl;
            cout << "|" << endl;
            break;
        case 4:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "| /|\\" << endl;
            cout << "|" << endl;
            break;
        case 5:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "| /|\\" << endl;
            cout << "| / " << endl; 
            break;
        case 6:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|  O" << endl;
            cout << "| /|\\" << endl;
            cout << "| / \\" << endl;
            break;
        default:
            cout << " __" << endl;
            cout << "|  |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
    }
}

bool checkWin(string sentence, string guess)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != guess[i])
        {
            return false;
        }
    }
    return true;
}

bool guessedAlready(char userguess, vector<char> userguesses)
{
    for (int i = 0; i < userguesses.size(); i++)
    {
        if (userguess == userguesses[i])
        {
            return true;
        }
    }
    return false;
}

void printSentence(string sentence, string& guess, char alpha)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (alpha == sentence[i])
        {
            guess += alpha;
        }
        else
        {
            guess += "_";
        }
    }
}

void clearScreen()
{
    system("clear");
}