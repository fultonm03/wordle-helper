#include "fileControl.hpp"

void makeNewWordFile(unsigned int letterCount, std::string filenameIn, std::string filenameOut)
{
    std::ofstream fileOut(filenameOut);
    std::fstream fileIn(filenameIn);

    if (!fileIn.is_open())
    {
        std::cerr << "Error: can't open input file " << filenameIn << std::endl;
        return;
    }

    if (!fileOut.is_open()) {
        std::cerr << "Error: can't open output file " << filenameOut << std::endl;
        return;
    }

    std::string temp;

    while (std::getline(fileIn, temp)) 
    {
        if (temp.length() - 1 == letterCount) 
        {
            fileOut << temp << std::endl;
        }   
    }
}

void convertWordsToWordleList(void)
{
    makeNewWordFile(5, ENGLISH_DICT, WORDLE_DICT);
}