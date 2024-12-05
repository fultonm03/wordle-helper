#include "main.hpp"


// Run this code first time to set up lis
// convertWordsToWordleList();

int main(int argc, char** argv)
{
    
    if (argc == 2 && argv[1][0] == '-'&& argv[1][1] == 'w' && argv[1][2] == '\0')
    {
        progLoop();    
    }
    else
    {
        std::string errorMsg;
        errorMsg = (argc == 2) ? "Unkown argument" : "Invalid argument count";
        std::cout << errorMsg << std::endl;
    }
    

    return 0;
}

void progLoop()
{
    Wordle wordle;

    wordle.addGreen(0, 'h');
    wordle.addGreen(1, 'e');
    wordle.addGreen(2, 'l');
    wordle.addGreen(3, 'l');

    wordle.updatePossibleWords();
    std::vector results = wordle.getPossibleWords();

    std::cout << "start list:" << std::endl;
    for (unsigned int i = 0; i < results.size(); i++)
    {
        std::cout << results.at(i) << std::endl;
    }

    wordle.printGreenCharacters();
}