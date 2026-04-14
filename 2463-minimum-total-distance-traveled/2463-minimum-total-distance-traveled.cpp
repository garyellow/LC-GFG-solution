class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ranges::sort(robot);
        ranges::sort(factory);

        vector dp(robot.size() + 1, vector<long long>(factory.size() + 1));

        for (int i = 0; i < robot.size(); i++) {
            dp[i][factory.size()] = LLONG_MAX;
        }

        for (int j = factory.size() - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> qq;
            qq.push_back({robot.size(), 0});

            for (int i = robot.size() - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);

                while (!qq.empty() && qq.front().first > i + factory[j][1]) {
                    qq.pop_front();
                }

                while (!qq.empty() && qq.back().second >= dp[i][j + 1] - prefix) {
                    qq.pop_back();
                }

                qq.push_back({i, dp[i][j + 1] - prefix});
                dp[i][j] = qq.front().second + prefix;
            }
        }

        return dp[0][0];
    }
};