class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> suffix(piles.size());
        suffix.back() = piles.back();
        for (int i = piles.size() - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        vector<vector<int>> dp(piles.size(), vector<int>(piles.size() + 1));

        for (int i = piles.size() - 1; i >= 0; i--) {
            for (int m = 1; m <= piles.size(); m++) {
                if (i + 2 * m >= piles.size()) {
                    dp[i][m] = suffix[i];
                } else {
                    for (int x = 1; x <= 2 * m; x++) {
                        int opponentScore = dp[i + x][max(x, m)];
                        int score = suffix[i] - opponentScore;
                        dp[i][m] = max(dp[i][m], score);
                    }
                }
            }
        }

        return dp[0][1];
    }
};