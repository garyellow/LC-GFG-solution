class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> prev(n, vector<int>(k + 1, numeric_limits<int>::min()));
        for (int i = 0; i < m; ++i) {
            vector<vector<int>> curr(
                n, vector<int>(k + 1, numeric_limits<int>::min()));

            for (int j = 0; j < n; ++j) {
                int gain = grid[i][j];
                int need = (gain > 0 ? 1 : 0);

                int limit = min(k, i + j);

                if (i == 0 && j == 0) {
                    curr[0][0] = 0;
                    continue;
                }

                for (int c = need; c <= limit; ++c) {
                    int best = numeric_limits<int>::min();

                    if (i > 0 &&
                        prev[j][c - need] != numeric_limits<int>::min()) {
                        best = max(best, prev[j][c - need] + gain);
                    }

                    if (j > 0 &&
                        curr[j - 1][c - need] != numeric_limits<int>::min()) {
                        best = max(best, curr[j - 1][c - need] + gain);
                    }

                    curr[j][c] = best;
                }
            }

            prev.swap(curr);
        }

        int ans = numeric_limits<int>::min();
        for (int c = 0; c <= k; ++c) {
            ans = max(ans, prev[n - 1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};