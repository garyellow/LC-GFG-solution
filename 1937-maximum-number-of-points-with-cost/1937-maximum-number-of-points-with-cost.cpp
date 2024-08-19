class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> dp(points.front().begin(), points.front().end());

        for (int r = 1; r < points.size(); ++r) {
            vector<long long> next(dp.size());
            vector<long long> leftMax(dp.size()), rightMax(dp.size());

            leftMax[0] = dp[0];
            for (int i = 1; i < dp.size(); i++) {
                leftMax[i] = max(leftMax[i - 1], dp[i] + i);
            }

            rightMax[dp.size() - 1] = dp[dp.size() - 1] - (dp.size() - 1);
            for (int i = dp.size() - 2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i + 1], dp[i] - i);
            }

            for (int i = 0; i < dp.size(); i++) {
                next[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
            }

            dp = next;
        }

        return *max_element(dp.begin(), dp.end());
    }
};