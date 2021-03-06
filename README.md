# c-wordfinder

This C program finds all the words in a given file that can be spelled with an inputed set of letters.

I developed this program with efficiency in mind, mainly for learning purposes. In this project I used some of the concepts learned in my Introduction to Algorithms and Data Structures class, such as linked-lists, hashing, hashtables (canonicalization and open-addressing), stacks and backtracking. 

Other than that I don't think this has much use, unless you would like to cheat on word games.

You can use the files inside /words to test the program, which contains a file containing words in English (/words/en -- [source](https://github.com/dwyl/english-words)) and another one containing words in Portuguese (/words/pt -- [source](https://www.ime.usp.br/~pf/dicios/index.html) IME-USP link.


Licensed under GNU GPLv3.

# Installation and Usage

Compile it with `make` and execute the program with `./wf <filepath>`.
