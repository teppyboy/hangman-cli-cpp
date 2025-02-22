#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.hpp"
#include "utils.hpp"

#define PROJECT_NAME "hangman"

void play(std::string word)
{
    int incorrect_guesses = 0;
    std::vector<int> known_letters;
    int max_guesses = sizeof(FIGURE) / sizeof(FIGURE[0]);
    while (incorrect_guesses < max_guesses)
    {
        if (known_letters.size() == word.size())
        {
            break;
        }
        clear();
        // std::cout << word << std::endl;
        std::cout << FIGURE[incorrect_guesses] << std::endl;
        std::cout << "Guess the word: ";
        print_word(word, known_letters);
        std::cout << std::endl
                  << "Enter a letter: ";
        char guess;
        std::cin >> guess;
        if (word.find(guess) != std::string::npos)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] == guess)
                {
                    known_letters.push_back(i);
                }
            }
        }
        else
        {
            incorrect_guesses++;
        }
    }
    if (incorrect_guesses == max_guesses)
    {
        clear();
        std::cout << FIGURE[incorrect_guesses] << std::endl;
        std::cout << "You lost! The word was: " << word << std::endl;
    }
    else
    {
        clear();
        std::cout << "You won! The word was: " << word << std::endl;
    }
}

int main(int argc, char **argv)
{
    // Load the wordlist
    auto wordlist = load_wordlist("assets/wordlist.txt");
    while (true)
    {
        auto seed = time(NULL);
        srand(seed);
        std::string word = wordlist[rand() % wordlist.size()];
        play(word);
        std::cout << "Play again? (y/n): ";
        char play_again;
        std::cin >> play_again;
        if (play_again != 'y')
        {
            break;
        }
    }
    return 0;
}
