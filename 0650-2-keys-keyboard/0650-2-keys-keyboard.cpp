class Solution {
public:
    static vector<int> dp;

    Solution() {
        if(dp.empty()) {
            dp.resize(1001);
            iota(dp.begin(), dp.end(), 0);
            dp[1] = 0;

            for(int i = 1; i < dp.size(); ++i) {
                for(int m = 2; i * m < dp.size(); ++m) {
                    dp[i * m] = min(dp[i * m], dp[i] + m);
                }
            }
        }
    }

    int minSteps(int n) {
        return dp[n];
    }
};

auto Solution::dp = vector<int>();