/*
 * @author Lewis Sneddon
 * @version 1.0 02/07/2020
 */

#include <iostream>
#include <ctime>

bool PlayGame(int Level);
void PrintIntroduction(int Difficulty);

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "Congratulations! You've won the game!\n";
    return 0;
}

void PrintIntroduction(int Difficulty)
{
    std::cout << "Level: " << Difficulty;
}

bool PlayGame(int Level)
{
    PrintIntroduction(Level);

    // Declare a 3 number code
    int CodeA = rand() % Level + Level;
    int CodeB = rand() % Level + Level;
    int CodeC = rand() % Level + Level;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cout << "Enter guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nWell done!\nMoving to the next level\n";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrond code ... try again\n";
        return false;
    }
}