# Hangman Console Game
This is the famous hangman game made in C++ from scratch playable on the console.

## Objective
The player's objective is to guess the hidden word/sentence.

## How to Play
1. The player starts by guessing one alphabet a time.
    1. If the alphabet **exists** in the hidden word/sentence, all instanes of the alphabet is revealed. 
    2. If the alphabet **does not exist**, the player has missed.
2. If the player is able to guess the word/sentence before 6 tries the player **WINS**
3. If not the player **LOSES**

## Rules
1. Player can guess alphabets only (a ~ z).
2. Player has 6 tries total.
3. Every guess of the alphabet has to be unique. **NOT THE SAME**