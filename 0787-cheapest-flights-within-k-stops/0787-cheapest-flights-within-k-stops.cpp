class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> roads(n);
        
        for(auto &&flight : flights) {
            roads[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> dp(n, INT_MAX);
        dp[src] = 0;
        
        for(int step = 0; step <= k; step++) {
            vector<int> dp2 = dp;
            
            for(int i = 0; i < n; i++) {
                if(dp2[i] != INT_MAX) {
                    for(auto &&[next, cost] : roads[i]) {
                        dp[next] = min(dp[next], dp2[i] + cost);
                    }
                }
            }
        }
        
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};