#include "dictionary.h"
extern int i = 0;
extern int k = 0;
void Dictionary::menu()
{
    cout<<"What you can do "<<endl;
    cout<<"1 -> Add word to dictionary "<<endl;
    cout<<"2 -> Show dictionary "<<endl;
    cout<<"3 -> Sort our dictionary "<<endl;
    cout<<"4 -> Write to file  "<<endl;
    cout<<"5 -> Exit "<<endl;
    int decision = 0;
    while(decision!=5)
    {
        cout<<"Enter your decision ";
        cin>>decision;

        switch(decision)
        {
        case 1:
            cout<<"Add word to dictionary -> 'e' - stop "<<endl;
            add();
            break;
        case 2:
            cout<<"Show dictionary "<<endl;
            showDictionary();
            break;
        case 3:
            cout<<"Sort dictionary "<<endl;
            sortDictionary();
            break;
        case 4:
            addToFile();
            break;
        }
    }
}


void Dictionary::add()
{
    string word;
    while(word!="e")
    {
        cout<<"Enter your word "<<endl;
        cin>>word;
        dictionary.insert(pair<int,string>(i,word));
        dictionary_words.push_back(word);
        i++;
    }

    dictionary.erase(prev(dictionary.end()));
    dictionary_words.pop_back();
}

void Dictionary::addToFile()
{

    cout<<"Write to  file.... "<<endl;
    ofstream out("Dictionary.txt");
    int k = 0;
    int counter = 0;
    for (auto it = dictionary_words.begin(); it != dictionary_words.end()-1; ++it)
    {
        if(dictionary_words[counter] != dictionary_words[counter+1])
        {
         out<<k<<":"<<*it<<endl;
         k++;
        }
        counter++;
    }
    out<<k<<":"<<dictionary_words.back();
    cout<<"Done"<<endl;
}


void Dictionary::showDictionary()
{
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

void Dictionary::sortDictionary()
{
    sort(dictionary_words.begin(), dictionary_words.end());

    for (auto it = dictionary_words.begin(); it != dictionary_words.end(); ++it)
    {
        cout <<*it<<endl;
    }
}
