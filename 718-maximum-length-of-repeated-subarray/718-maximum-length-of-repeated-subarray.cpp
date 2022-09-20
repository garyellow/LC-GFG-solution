class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
        
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                    dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
            }
        }
        
        int cnt = 0;
        for(auto &&i : dp)
            for(auto &&j : i)
                cnt = max(cnt, j);
        
        return cnt;
    }
};