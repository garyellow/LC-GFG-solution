class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i , int turn , vector<int>& prices) {
        if(i >= prices.size()) return 0;
        else if(dp[i][turn] != -1) return dp[i][turn];
        else if(turn == 0)
            return dp[i][turn] = max(-prices[i] + dfs(i + 1 , 1 , prices), dfs(i + 1 , 0 , prices));
        else if(turn == 1)
            return dp[i][turn] = max(prices[i] + dfs(i + 1 , 2 , prices), dfs(i + 1 , 1 , prices));
        else
            return dp[i][turn] = dfs(i + 1 , 0 , prices);
    }
    
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(3, -1));
        return dfs(0, 0, prices);
    }
};