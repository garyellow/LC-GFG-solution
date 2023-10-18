class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> dp(n);
        vector<bool> root(n, true);

        for(int i = 0; i < relations.size(); i++) {
            root[relations[i][1] - 1] = false;
            graph[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(root[i]) {
                ans = max(ans, dfs(i, graph, time, dp));
            }
        }

        return ans;
    }

    int dfs(int cur, vector<vector<int>> &graph, vector<int>& time, vector<int> &dp) {
        if(dp[cur]) return dp[cur];

        int sum = 0;
        for(auto &&next : graph[cur]) {
            sum = max(sum, dfs(next, graph, time, dp));
        }

        return dp[cur] = time[cur] + sum;
    }
};