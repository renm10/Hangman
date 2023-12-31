# Hangman Console Game
[![jpn](https://img.shields.io/badge/lang-jpn-red.svg)](https://github.com/renm10/Hangman/blob/main/README-jp.md)

This is the famous hangman game made in C++ from scratch playable on the console.   
It utilizes the [Random word API](https://random-word-api.herokuapp.com/home) to fetch random words and [curl](https://curl.se/) to process HTTP requests.

## Objective
The player's objective is to guess the hidden word.

## How to Play
1. The player starts by guessing one alphabet a time.
    1. If the alphabet **exists** in the hidden word, all instanes of the alphabet is revealed. 
    2. If the alphabet **does not exist**, the player has missed.
2. If the player is able to guess the word before 6 tries the player **WINS**
3. If not the player **LOSES**

## Rules
1. Player can guess alphabets only (a ~ z).
2. Player has 6 tries total.
3. Every guess of the alphabet has to be unique. **NOT THE SAME**

## Requirements
[curl](https://curl.se/)

## Compile and Run
1. Compile
    ```
    g++ main.cpp -o programName -lcurl
    ```
2. Run
    ```
    ./programName
    ```

## Screenshots
<img width="219" alt="HangmanTitle" src="https://github.com/renm10/Hangman/assets/43124584/660bc57b-b98b-4ae7-99e8-a0fed773b143"><BR CLEAR-ALL/>
<img width="240" alt="HangmanLoss" src="https://github.com/renm10/Hangman/assets/43124584/cded9892-8bc7-405d-9640-3e9f4c190425"><BR CLEAR-ALL/>
<img width="315" alt="HangmanError" src="https://github.com/renm10/Hangman/assets/43124584/efb60cb0-8ec5-410d-a598-e02d0bd5dea0"><BR CLEAR-ALL/>
