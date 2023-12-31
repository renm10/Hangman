#  ハングマン （コンソールゲーム）
[![en](https://img.shields.io/badge/lang-en-blue.svg)](https://github.com/renm10/Hangman/blob/main/README.md)

かの有名なハングマンというゲームをコンソールで遊べるようにC++で作られたものである。   
[Random word API](https://random-word-api.herokuapp.com/home)を使いランダムで英単語を取得し[curl](https://curl.se/)というツールを使いhttpリクエストを処理している。

## 目標
プレイヤーの目標は隠された単語を文字数、自分が以前当てたアルファベットを頼りに当てる事である。
## 遊び方
1. プレイヤーはまず隠された単語に入っているであろうアルファベットを一つ入力する。
    1. アルファベットが**含まれている**場合、その単語に含まれている全てのアルファベットがヒントとして見えるようになります。
    2. アルファベットが**含まれていない**場合、プレイヤーのミスとなります。
2. プレイヤーが6回以内に隠された単語を当てる事ができた場合プレイヤーの**勝利**となります。
3. もし6回以内に当てられなければ**敗北**となります。

## ルール
1. プレイヤーは (a~z)　のアルファベットのみを推測として入力出来ます。
2. プレイヤーは全部で6回のチャンスがあります。
3. プレイヤーが入力するアルファベットは異なる物のみが推測とし数えられます。（同じアルファベットを2回入力してもミスとして数えられません）

## 必須
[curl](https://curl.se/)

## コンパイルと実行
1. 以下でコンパイルします。
    ```
    g++ main.cpp -o programName -lcurl
    ```
2. 以下でゲームを実行します。
    ```
    ./programName
    ```
## スクリーンショット
<img width="219" alt="HangmanTitle" src="https://github.com/renm10/Hangman/assets/43124584/660bc57b-b98b-4ae7-99e8-a0fed773b143"><BR CLEAR-ALL/>
<img width="240" alt="HangmanLoss" src="https://github.com/renm10/Hangman/assets/43124584/cded9892-8bc7-405d-9640-3e9f4c190425"><BR CLEAR-ALL/>
<img width="315" alt="HangmanError" src="https://github.com/renm10/Hangman/assets/43124584/efb60cb0-8ec5-410d-a598-e02d0bd5dea0"><BR CLEAR-ALL/>
