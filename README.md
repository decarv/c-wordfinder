# c-wordfinder

This C program aggregates all the words of a given file that can be spelled with a inputed set of lettes. The /words folders contains two files with words in English (/words/en) and in Portuguese (/words/pt) that can be used to test the program. The English file was downloaded from [this repository](https://github.com/dwyl/english-words) and the Portuguese file was downloaded from [this](https://www.ime.usp.br/~pf/dicios/index.html) IME-USP link.

I developed this program with efficiency in mind, mainly for learning purposes. In this project I used some of the concepts learned in my Introduction to Algorithms and Data Structures class, such as linked-lists, hashing, hashtables (canonicalization and open-addressing), stacks and backtracking. 

Other than that I don't think this has much use, unless you would like to cheat on word games.

Licensed under GNU GPLv3.

# Installation and Usage

Compile it with `make` and execute the program with `./wf <filepath>`.
