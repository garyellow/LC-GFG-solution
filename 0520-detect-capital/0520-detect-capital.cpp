class Solution {
public:
    bool detectCapitalUse(string &word)
    {
        int upper = count_if(word.begin(), word.end(), [](int x){return isupper(x);});

        return upper == 0 || upper == word.size() || (upper == 1 && isupper(word.front()));
    }
};