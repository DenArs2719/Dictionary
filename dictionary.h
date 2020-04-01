#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Dictionary
{
    map<int,string> dictionary;
    vector<string> dictionary_words;

public:
    void menu(); ///show menu
    void add(); ///add word to dictionary
    void showDictionary(); ///show dictionary
    void sortDictionary(); ///sort dictionary
    void addToFile(); /// add our words to file
};
#endif // DICTIONARY_H
