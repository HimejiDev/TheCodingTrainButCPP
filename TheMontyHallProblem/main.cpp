#include "iostream"
#include "random"
#include "string"

class door
{
public:
    std::string prize = "💩";
};

int rand_int(int min, int max)
{
    if (min > max)
        min = max;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(gen);
}

int revealDoor(int picked, int winner)
{
    bool isValid = false;
    int revealInt = 0;
    while (!isValid)
    {
        revealInt = rand_int(0, 2);
        if (revealInt != picked && revealInt != winner)
        {
            isValid = true;
        }
    }
    return revealInt;
}

int main()
{
    // stats
    float total_plays = 0;
    float stayWins = 0;
    float switchWins = 0;

    std::cout << "How many rounds do you want to run? :";
    std::cin >> total_plays;

    for (int i = 0; i < total_plays; i++)
    {
        // vars
        door doors[3] = {};
        int doorPicked = rand_int(0, 2);
        int winnerDoor = rand_int(0, 2);
        int reveal = revealDoor(doorPicked, winnerDoor);

        // win or lose
        std::string stay;
        std::string _switch;

        if (doorPicked == winnerDoor)
        {
            stay = "W";
            stayWins += 1;
            _switch = "L";
        }
        else
        {
            stay = "L";
            _switch = "W";
            switchWins += 1;
        }

        doors[winnerDoor].prize = "🎁";
        std::cout << doors[0].prize << " " << doors[1].prize << " " << doors[2].prize << " | << " << i << std::endl;
        std::cout << "st: " << stay << " | sw: " << _switch << std::endl;
    }
    float stayWinRate = (stayWins / total_plays) * 100;
    float switchWinRate = (switchWins / total_plays) * 100;
    std::cout << "stay winrate: " << stayWinRate << std::endl;
    std::cout << "switch winrate: " << switchWinRate << std::endl;

        return 0;
}