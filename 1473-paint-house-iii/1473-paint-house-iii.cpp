class Solution {
public:
    vector<vector<vector<long>>> dp;
    vector<vector<vector<bool>>> is_gone;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp = vector<vector<vector<long>>>(m, vector<vector<long>>(n, vector<long>(target, INT_MAX)));
        is_gone = vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(target)));
        
        if(houses.front())
        {
            dp[0][houses.front() - 1][0] = 0;
            is_gone[0][houses.front() - 1][0] = true;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                dp[0][i][0] = cost[0][i];
                is_gone[0][i][0] = true;
            }
        }
        
        long temp = INT_MAX;
        for(int i = 0; i < n; i++)
            temp = min(temp, check(m - 1, i, target - 1, houses, cost));
        
        return temp == INT_MAX ? -1 : temp;
    }
    
    long check(int m, int n, int t, const vector<int>& h, const vector<vector<int>>& c)
    {
        if(t < 0 || t > m) return INT_MAX;
        if(is_gone[m][n][t] == false)
        {
            is_gone[m][n][t] = true;
            
            if(h[m] == n + 1 || h[m] == 0)
            {
                long temp = INT_MAX;
                for(int i = 0; i < c.front().size(); i++)
                {
                    if(i == n) temp = min(temp, check(m - 1, i, t, h, c) + (h[m] ? 0 : c[m][n]));
                    else temp = min(temp, check(m - 1, i, t - 1, h, c) + (h[m] ? 0 : c[m][n]));
                }
                dp[m][n][t] = temp;
            }
        }
        return dp[m][n][t];
    }
};