class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        
        bool dp[s2.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        
        for(int i = 0; i < s2.size(); i++)
            dp[i + 1] = dp[i] && s2[i] == s3[i];
        
        for(int i1 = 0; i1 < s1.size(); i1++)
        {
            dp[0] = dp[0] && s1[i1] == s3[i1];
            
            for(int i2 = 0; i2 < s2.size(); i2++)
                dp[i2 + 1] = ((dp[i2 + 1] && s1[i1] == s3[i1 + i2 + 1]) || (dp[i2] && s2[i2] == s3[i1 + i2 + 1]));
        }
        
        return dp[s2.size()];
    }
};