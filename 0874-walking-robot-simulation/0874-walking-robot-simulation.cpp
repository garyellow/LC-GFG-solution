class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> direction({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});

        set<pair<int, int>> obstacles_set;
        for (const auto& obstacle : obstacles) {
            obstacles_set.insert({obstacle.front(), obstacle.back()});
        }

        int dir = 0, x = 0, y = 0, ans = 0;
        for (auto command : commands) {
            if (command < 0) {
                switch (command) {
                case -1:
                    dir = (dir + 1) % 4;
                    break;
                case -2:
                    dir = (dir - 1 + 4) % 4;
                    break;
                }
            } else {
                while (command-- &&
                       !obstacles_set.count({x + direction[dir].first,
                                             y + direction[dir].second})) {
                    x = x + direction[dir].first;
                    y = y + direction[dir].second;
                }
                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }
};