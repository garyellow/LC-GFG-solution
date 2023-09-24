class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        array<array<double, 101>, 101> dp({(double)poured});

        for (size_t i = 0; i < 100; i++)
            for (size_t j = 0; j <= i; j++)
                if (dp[i][j] > 1) {
                    dp[i + 1][j] += (dp[i][j] - 1) / 2;
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
                    dp[i][j] = 1;
                }

        return dp[query_row][query_glass];
    }
};