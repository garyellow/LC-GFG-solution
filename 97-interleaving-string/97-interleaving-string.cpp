class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
        dp.front().front() = true;
        
        for(int i = 0; i < s1.size(); i++)
            dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
        
        for(int i = 0; i < s2.size(); i++)
            dp[0][i + 1] = dp[0][i] && s2[i] == s3[i];
        
        for(int i1 = 0; i1 < s1.size(); i1++)
            for(int i2 = 0; i2 < s2.size(); i2++)
                dp[i1 + 1][i2 + 1] = ((dp[i1][i2 + 1] && s1[i1] == s3[i1 + i2 + 1]) || (dp[i1 + 1][i2] && s2[i2] == s3[i1 + i2 + 1]));
        
        // for(auto &&i : dp)
        // {
        //     for(auto &&j : i)
        //         cout << j << ' ';
        //     cout << endl;
        // }
        
        return dp.back().back();
    }
};