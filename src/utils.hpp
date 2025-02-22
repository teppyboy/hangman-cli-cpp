#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
/* 
    Clears the console, hopefully cross-platform. Doesn't work on older Windows
    according to the source.

    Credits to: https://stackoverflow.com/a/43884673
*/
void clear() {
    printf("\033c");
}

/*
    Prints the word with the known letters filled in.
*/
void print_word(std::string word, std::vector<int> known_letters)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (std::find(known_letters.begin(), known_letters.end(), i) != known_letters.end())
        {
            std::cout << word[i];
        }
        else
        {
            std::cout << "-";
        }
    }
}

std::vector<std::string> load_wordlist(std::string filename)
{
    std::vector<std::string> wordlist;
    std::ifstream f(filename);
    std::string line;
    while (std::getline(f, line))
    {
        wordlist.push_back(line);
    }
    return wordlist;
}