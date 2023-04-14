class Solution {
public:
    int longestPalindromeSubseq(string &s) {
        vector<int> dp(s.size());
        
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> temp(s.size());
            temp[i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) temp[j] = 2 + dp[j-1];
                else temp[j] = max(dp[j], temp[j-1]);
            }
            
            dp = temp;
        }
        
        return dp.back();
    }
};