class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        int ans = dfs(0, 0, nums1, nums2, dp);
        if(ans) return ans;
        else return max(
            *max_element(nums1.begin(), nums1.end()) * *min_element(nums2.begin(), nums2.end()),
            *min_element(nums1.begin(), nums1.end()) * *max_element(nums2.begin(), nums2.end())
            );
    }

    int dfs(int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(n == nums1.size() || m == nums2.size()) return 0;
        if(dp[n][m] != INT_MIN) return dp[n][m];

        dp[n][m] = max(dp[n][m], nums1[n] * nums2[m] + dfs(n + 1, m + 1, nums1, nums2, dp));
        dp[n][m] = max(dp[n][m], dfs(n + 1, m, nums1, nums2, dp));
        dp[n][m] = max(dp[n][m], dfs(n, m + 1, nums1, nums2, dp));
        dp[n][m] = max(dp[n][m], dfs(n + 1, m + 1, nums1, nums2, dp));

        return dp[n][m];
    }
};