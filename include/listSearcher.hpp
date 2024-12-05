#ifndef _LISTSEARCHER_HPP
#define _LISTSEARCHER_HPP

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <chrono>
#include <algorithm>

#include "fileControl.hpp"

class Wordle
{
    private:
        std::vector<std::string> possibleWords;
        std::vector<char> greyCharacters;
        std::vector<char> yellowCharacters[5];
        char greenCharacters[5];
        int remainingWordCount;

    public:
        Wordle();
        ~Wordle();
        void updatePossibleWords(void);
        std::vector<std::string> getPossibleWords(void);
        void addGrey(char c);
        void addYellow(int index, char c);
        void addGreen(int index, char c);
        void printGreenCharacters(void);
};

#endif