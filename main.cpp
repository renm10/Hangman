#include <iostream>
#include <stdlib.h> //For system (cls and clear)
#include <vector>
#include <curl/curl.h> //For Handling HTTP requests (API)

using namespace std;

size_t writeCallBack(void*, size_t, size_t, void*); 
string trimWord(string&);
void printTitle();
void printMan(int);
bool checkWin(string, string);
void getValidGuess(char&, vector<char>, string, int, string);
bool guessedAlready(char, vector<char>);
bool isOneCharLong(string);
void clearScreen();

int main()
{
    //Obtain Information using API using libcurl
    CURL *curl;
    CURLcode res;
    string readWord;

    curl = curl_easy_init(); //Initiate
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://random-word-api.herokuapp.com/word"); //Get Info
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack); //Get size of the data returned
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readWord); //Write the response into the string

        res = curl_easy_perform(curl); //Send a request

        curl_easy_cleanup(curl);
    }

    string word = trimWord(readWord); //Remove [" and "] of the returned string
    string guess = ""; //Players currently guessed sentence
    vector<char> userguesses; //Keeps track of all of the players guesses
    char temp;
    string guessedString;
    char userguess;
    int miss = 0; //Keeps track of number of misses the user has


    //Initialize the users guess
    for (int i = 0; i < word.length(); i++)
    {
        if (isspace(word[i]))
        {
            guess += ' ';
        }
        else
        {
            guess += '_';
        }
    }

    printTitle();
    
    while (miss < 6) //Player has 6 tries
    {

        //Get and checkfor valid user guess.
        getValidGuess(userguess, userguesses, guess, miss, "");

        userguesses.push_back(userguess);

        bool matchfound = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (userguess == word[i])
            {
                temp = userguess;
                matchfound = true;
            }
            else
            {
                temp = '\0';
            }

            if (temp == word[i])
            {
                guess[i] = temp;
            }
        }


        if (!matchfound) 
        {
            miss++;
        }

        if (checkWin(word, guess))
        {
            clearScreen();
            cout << "\"" << word << "\"" << " is correct!!" << endl;
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
    cout << "Correct Answer: " << word << endl;
}

//Callback function for curl. Returns the number of bytes of data returned.
size_t writeCallBack(void *contents, size_t size, size_t nmemb, void *userdata)
{
    ((string*)userdata)->append((char*)contents, size *nmemb);
    return size *nmemb;
}

//Removes [" and "] of the string
string trimWord(string &word)
{
    word.erase(0,2);
    word.erase(word.size()-2, 2);
    cout << word << endl;
    return word;
}

//Prints the Title
void printTitle()
{
    clearScreen();
    cout << "*************************" << endl;
    cout << "*        HANGMAN        *" << endl;
    cout << "* <Press Enter to Play> *"<< endl;
    cout << "*************************" << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    clearScreen();
}

//Print the hangman figure
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

//Check if the player won or not
bool checkWin(string word, string guess)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != guess[i])
        {
            return false;
        }
    }
    return true;
}

//Ask the user and get a valid guess
void getValidGuess(char &userguess, vector<char> userguesses, string guess, int miss, string errMsg)
{
    string guessedString;

    clearScreen();
    printMan(miss);
    cout << endl;
    cout << guess << "   " << errMsg << endl;
    errMsg = ""; //Reset the Error State

    cout << "Enter Guess [a ~ z]: ";
    cin >> guessedString;
    cout << endl;

    if (!isOneCharLong(guessedString)) //Check if the input is one character long
    {
        errMsg = "Guess has to be one character long!";
        getValidGuess(userguess, userguesses, guess, miss, errMsg);
    }
    else
    {
        userguess = guessedString[0];
        if (!isalpha(userguess)) //Check if it is an alphabet
        {   
            errMsg = "Guess has to be an alphabet!";
            getValidGuess(userguess, userguesses, guess, miss, errMsg);
        }
        else
        {
            if (guessedAlready(userguess, userguesses)) //Check if the guess hasn't been guessed already
            {
                errMsg += userguess;
                errMsg += " has been guessed already";
                getValidGuess(userguess, userguesses, guess, miss, errMsg);
            }
        }
    }
}

//Checks if the players guess was guessed before or not
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

//Checks if the given string is one character long
bool isOneCharLong(string userguess)
{
    if (userguess.size() == 1)
    {
        return true;
    }
    return false;
}

//Clear the console depending on the OS
void clearScreen()
{
    #ifdef WINDOWS //Windows cls command 
        system("cls");
    #else 
        system("clear");
    #endif
}