#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    std::cout << R"(
                       | WELCOME TO |
 _____           _       ______                _             
/  __ \         | |      | ___ \              | |            
| /  \/ ___   __| | ___  | |_/ /_ __ ___  __ _| | _____ _ __ 
| |    / _ \ / _` |/ _ \ | ___ \ '__/ _ \/ _` | |/ / _ \ '__|
| \__/\ (_) | (_| |  __/ | |_/ / | |  __/ (_| |   <  __/ |   
 \____/\___/ \__,_|\___| \____/|_|  \___|\__,_|_|\_\___|_|  

                                | Created by Stephen Wilson |
    )" << std::endl;
    std::cout << "There Are 5 Levels Of Security" << std::endl;
}

bool PlayGame()
{
    srand(time(NULL));

    const int CodeA = rand() % 5 + 1;
    const int CodeB = rand() % 5 + 1;
    const int CodeC = rand() % 5 + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "\n-> There are 3 numbers in the code";
    std::cout << "\n-> The codes add-up to: " << CodeSum;
    std::cout << "\n-> The codes multiply to give: " << CodeProduct << std::endl;

    // initialize guess variables
    int GuessA;
    int GuessB;
    int GuessC;

    // ask for user input
    std::cout << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // if/else statement for condition of game
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Nice Work Agent!" << std::endl;
        std::cout << "___________________________________________________" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Alarms Went Off You Were Caught!";
        std::cout << "\nCorrect Code Was: " << CodeA << "-" << CodeB << "-" << CodeC << std::endl;
        std::cout << "___________________________________________________" << std::endl;
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    int MaxLevel = 6;

    PrintIntroduction();

    while (LevelDifficulty <= MaxLevel)
    {
        std::cout << "\nYou are a secret agent breaking into a level " << LevelDifficulty;
        std::cout << " secure server room..\nEnter the correct code to continue.. ex: 1 2 3\n"
                  << std::endl;

        bool bLevelComplete = PlayGame();
        // helps with loop
        std::cin.clear();  // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            std::cout << "\n~ Well Done You Completed Level " << LevelDifficulty << " ~" << std::endl;
            ++LevelDifficulty;
        }
        if (LevelDifficulty == MaxLevel)
        {
            std::cout << R"(
                
 _______ _______ _______ _______ _______ _______    _______ _______ _______ _      ________________ ______  
(  ___  (  ____ (  ____ (  ____ (  ____ (  ____ \  (  ____ (  ____ (  ___  ( (    /\__   __(  ____ (  __  \ 
| (   ) | (    \| (    \| (    \| (    \| (    \/  | (    \| (    )| (   ) |  \  ( |  ) (  | (    \| (  \  )
| (___) | |     | |     | (__   | (_____| (_____   | |     | (____)| (___) |   \ | |  | |  | (__   | |   ) |
|  ___  | |     | |     |  __)  (_____  (_____  )  | | ____|     __|  ___  | (\ \) |  | |  |  __)  | |   | |
| (   ) | |     | |     | (           ) |     ) |  | | \_  | (\ (  | (   ) | | \   |  | |  | (     | |   ) |
| )   ( | (____/| (____/| (____//\____) /\____) |  | (___) | ) \ \_| )   ( | )  \  |  | |  | (____/| (__/  )
|/     \(_______(_______(_______\_______\_______)  (_______|/   \__|/     \|/    )_)  )_(  (_______(______/ 
                                                                                                            

            )" << std::endl;
            return 0;
        }
        else if (!bLevelComplete)
        {
            return 0;
        }
    }

    return 0;
}