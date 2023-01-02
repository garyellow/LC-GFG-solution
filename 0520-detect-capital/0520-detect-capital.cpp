class Solution {
public:
    bool detectCapitalUse(string &word)
    {
        int lower = count_if(word.begin(), word.end(), [](int x){return islower(x);});

        return lower == 0 || lower == word.size() || (lower == word.size() - 1 && isupper(word.front()));
    }
};