class Solution {
public:
    int minInsertions(string s) {
        vector<int> dp(s.size());
        for (int i = s.size() - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < s.size(); j++) {
                int temp = dp[j];
                if (s[i] == s[j]) dp[j] = prev;
                else dp[j] = min(dp[j], dp[j - 1]) + 1;
                
                prev = temp;
            }
        }
        return dp.back();
    }
};