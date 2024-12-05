#include "listSearcher.hpp"


Wordle::Wordle()
{
    std::fstream dictionary(WORDLE_DICT);

    std::string temp;

    for (int i = 0; i < 5; i++)
    {
        this->greenCharacters[i] = '#';
    }

    if (!dictionary.is_open())
    {
        std::cerr << "Error: can't open input file " << WORDLE_DICT << std::endl;
        exit(1);
    }

    auto startTime = std::chrono::high_resolution_clock::now();

     
    while (std::getline(dictionary, temp))
    {
        this->possibleWords.push_back(temp);
        this->remainingWordCount++;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = endTime - startTime;
    std::cout << "Load Time: " << elapsed.count() << std::endl; 
}

Wordle::~Wordle()
{
    std::cout << this << " deleted." << std::endl;
}

void Wordle::addGrey(char c)
{
    this->greyCharacters.push_back(c);
}

void Wordle::addYellow(int index, char c)
{
    this->yellowCharacters[index].push_back(c);
}

void Wordle::addGreen(int index, char c)
{
    this->greenCharacters[index] = c;
}

void Wordle::printGreenCharacters(void)
{
    std::cout << "Green: " << this->greenCharacters << std::endl;
}

// This shit is like O(n^3) if not worse!!
void Wordle::updatePossibleWords()
{
    
    for (int i = 0; i < remainingWordCount; i++)
    {
        bool remove = false;
        std::string currentWord = this->possibleWords.at(i);

        // Check if it contains GREY letters
        for (unsigned int j = 0; j < this->greyCharacters.size(); j++)
        {
            if (currentWord.find(this->greyCharacters.at(j)) != std::string::npos)
            {
                remove = true;
                // this->possibleWords.erase(this->possibleWords.begin() + i);
            }
        }

        // Check if it lacks GREEN letters
        for (int j = 0; j < 5; j++)
        {
            if (this->greenCharacters[j] != '#' && currentWord.at(j) != this->greenCharacters[j])
            {
                remove = true;
                // this->possibleWords.erase(this->possibleWords.begin() + i);
            }
        }

        // Check if it lacks YELLOW letters
        for (unsigned int j = 0; j < this->yellowCharacters->size(); j++)
        {
            for (unsigned int k = 0; k < this->yellowCharacters[j].size(); k++)
            {
                if (currentWord.find(yellowCharacters[j].at(k)) == std::string::npos)
                {
                    remove = true;
                    // this->possibleWords.erase(this->possibleWords.begin() + i);
                }
            }
        }

        // Check if it has YELLOW letters where they shouldnt be
        for (unsigned int j = 0; j < this->yellowCharacters->size(); j++)
        {
            for (int k = 0; k < 5; k++)
            {
                auto pos = std::find(yellowCharacters[k].begin(), yellowCharacters[k].end(), currentWord[k]);
                if (pos != this->yellowCharacters[k].end())
                {
                    remove = true;
                    // this->possibleWords.erase(this->possibleWords.begin() + i);
                }
            }
        }
        if (remove)
        {
            this->possibleWords.erase(this->possibleWords.begin() + i);
            i--;   
        }
    }
}

std::vector<std::string> Wordle::getPossibleWords()
{
    return this->possibleWords;
}