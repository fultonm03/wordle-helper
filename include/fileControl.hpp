// Includes //
#include <string>
#include <iostream>
#include <fstream>

// Defines //
#define ENGLISH_DICT "data/words_alpha.txt"
#define TEST_DICT "data/testIn.txt"
#define WORDLE_DICT "data/wordleWords.txt"

// Prototypes //
void makeNewWordFile(unsigned int letterCount, std::string filenameIn, std::string filenameOut);
void convertWordsToWordleList(void);