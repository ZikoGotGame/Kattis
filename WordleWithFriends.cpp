#include <iostream>
#include <unordered_map>
#include <unordered_set>

void check_guess(const std::string &word, const std::string &guess, std::unordered_map<char, std::unordered_set<int>> &letterIndex,
                 std::unordered_map<char, int> letterCount)
{
    for (int i = 0; i < 5; ++i)
    {
        if (word[i] != '0' && guess[i] != word[i])
            return;
        if (word[i] == '0' && letterIndex[guess[i]].find(i) == letterIndex[guess[i]].end())
            return;
        if (letterCount.find(guess[i]) != letterCount.end())
            --letterCount[guess[i]];
    }
    for (const auto &pair : letterCount)
        if (pair.second > 0)
            return;
    std::cout << guess << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::unordered_map<char, std::unordered_set<int>> letterIndex;
    std::unordered_map<char, int> letterCount;
    for (int i = 65; i <= 90; ++i)
        letterIndex[i] = {0, 1, 2, 3, 4};
    std::string word = "00000";
    int N, W;
    std::cin >> N >> W;
    for (int i = 0; i < N; ++i)
    {
        std::string guess, result;
        std::unordered_map<char, int> wordLetterCount;
        std::cin >> guess >> result;
        for (int j = 0; j < 5; ++j)
        {
            switch (result[j])
            {
            case 'G':
                word[j] = guess[j];
                ++wordLetterCount[guess[j]];
                break;
            case 'Y':
                letterIndex[guess[j]].erase(j);
                ++wordLetterCount[guess[j]];
            default:
                continue;
            }
        }
        for (int j = 0; j < 5; ++j)
        {
            if (result[j] == '-')
            {
                if (wordLetterCount.find(guess[j]) == wordLetterCount.end())
                    letterIndex[guess[j]].clear();
                else
                    letterIndex[guess[j]].erase(j);
            }
        }
        for (const auto &pair : wordLetterCount)
            letterCount[pair.first] = std::max(pair.second, letterCount[pair.first]);
    }
    for (int i = 0; i < W; ++i)
    {
        std::string guess;
        std::cin >> guess;
        check_guess(word, guess, letterIndex, letterCount);
    }
    return 0;
}
