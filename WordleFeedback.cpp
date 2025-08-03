#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<char, int> secretCount, guessCount;
    std::string secret, guess, answer = "00000";
    std::cin >> secret >> guess;
    for (int i = 0; i < 5; ++i)
    {
        if (secret[i] == guess[i])
            answer[i] = 'G';
        else
            ++secretCount[secret[i]];
    }
    for (int i = 0; i < 5; ++i)
    {
        if (answer[i] != 'G')
        {
            if (guessCount[guess[i]] < secretCount[guess[i]])
            {
                answer[i] = 'Y';
                ++guessCount[guess[i]];
            }
            else
                answer[i] = '-';
        }
    }
    std::cout << answer;
    return 0;
}
