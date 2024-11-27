class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }

        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 0);

        vector<int> results;
        for (auto& query : queries) {
            graph[query[0]].push_back(query[1]);
            if (dp[query[1]] > dp[query[0]] + 1) {
                dp[query[1]] = dp[query[0]] + 1;

                unordered_set<int> visited({query[1]});
                queue<int> q({query[1]});
                while (q.size()) {
                    auto cur = q.front();
                    q.pop();

                    for (auto& next : graph[cur]) {
                        if (!visited.count(next)) {
                            dp[next] = min(dp[next], dp[cur] + 1);
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }

            results.push_back(dp.back());
        }

        return results;
    }
};