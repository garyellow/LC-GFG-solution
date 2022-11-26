class Solution {
public:
    vector<int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        dp = vector<int>(startTime.size(),-1);
        
        vector<vector<int>> J;
        for (int i = 0; i < startTime.size(); i++) J.push_back({startTime[i], endTime[i], profit[i]});
        sort(J.begin(), J.end());        
        
        return dfs(0, J);
    }
    
    int dfs(int i, vector<vector<int>> &J) {
        if (i >= dp.size()) return 0;
        if (dp[i] >= 0) return dp[i];

        vector<int> v = {J[i][1], 0, 0};
        int k = lower_bound(J.begin(), J.end(), v) - J.begin();
        return dp[i] = max(dfs(i+1, J), J[i][2] + dfs(k, J));
    }
};