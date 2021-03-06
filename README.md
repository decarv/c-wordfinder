# Project

Aggregate words that are spelled with the same letters in a dictionary.

1. Iterate through an Portuguese Dictionary;
2. Sort the letters of a word and store in sortedword;
3. Store the word based on a hash of the sortedword and store all collisions with a list;
4. Collisions for a different set of letters should be treated with open addressing;
5. For each hash entry, there will be all the words that can be written with a combination of n letters;
6. Save the hashmap in a bit stream @ words.bin.

Find all the words for n given letters.

1. Sort the sequence of letters and find the buckets of the respective words (from 1 to n letters);
2. Print the words in a table.
