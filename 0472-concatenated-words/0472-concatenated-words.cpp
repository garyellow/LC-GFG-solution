class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (auto &&word : words) 
            words_set.insert(word);
        
        vector<string> res;
        for (auto &&word : words) {
            vector<int> dp(word.size() + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < word.size(); i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= word.size(); j++) {
                    if (j - i < word.size() && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[word.size()]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        
        return res;
    }
};