class Solution {
public:
    int numWays(vector<string>& words, string &target) {
        vector<int> dp(target.size() + 1);
        dp[0] = 1;
        
        vector<vector<int>> count(words.front().size(), vector<int>(26));
        for (const string& word : words) {
            for (int i = 0; i < words.front().size(); i++) {
                count[i][word[i] - 'a']++;
            }
        }
        
        for (int i = 0; i < words.front().size(); i++) {
            for (int j = target.size() - 1; j >= 0; j--) {
                dp[j + 1] += int((long)dp[j] * count[i][target[j] - 'a'] % int(1e9 + 7));
                dp[j + 1] %= int(1e9 + 7);
            }
        }
        
        return dp.back();
    }
};