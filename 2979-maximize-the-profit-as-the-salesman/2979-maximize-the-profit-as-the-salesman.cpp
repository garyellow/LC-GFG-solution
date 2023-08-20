class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1);

        vector<vector<vector<int>>> record(n);
        
        for(auto &&offer : offers) {
            record[offer[1]].push_back(offer);
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (auto &&offer : record[i - 1]) {
                dp[i] = max(dp[i], dp[offer[0]] + offer[2]);
            }
        }
        
        return dp[n];
    }
};