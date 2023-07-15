class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int m = INT_MIN;
        
        for(auto &num : arr) {
            m = max(m, dp[num] = dp[num - difference] + 1);
        }
        
        return m;
    }
};