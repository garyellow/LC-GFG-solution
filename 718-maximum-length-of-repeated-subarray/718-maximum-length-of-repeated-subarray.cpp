class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
        
        int cnt = 0;
        for(int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
                cnt = max(cnt, dp[i][j] = (nums1[i] == nums2[j]) ? ((i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1) : 0);
        
        return cnt;
    }
};