class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int, int, char, int>> robots;

        for (int i = 0; i < positions.size(); ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }

        ranges::sort(robots);

        vector<int> st;
        for (int i = 0; i < robots.size(); ++i) {
            if (st.empty()) {
                st.push_back(i);
                continue;
            }

            auto&& [_, healthy, direction, __] = robots[i];

            while (!st.empty() && get<2>(robots[st.back()]) == 'R' && direction == 'L' && healthy > 0) {
                auto&& [_, bhealthy, __, ___] = robots[st.back()];
                if (bhealthy > healthy) {
                    --bhealthy;
                    healthy = 0;
                } else if (bhealthy < healthy) {
                    --healthy;
                    bhealthy = 0;
                } else {
                    healthy = 0;
                    bhealthy = 0;
                }

                if (bhealthy == 0) {
                    st.pop_back();
                }
            }

            if (healthy > 0) {
                st.push_back(i);
            }
        }

        vector<int> result;
        ranges::sort(st, [&](auto& a, auto& b) {
            return get<3>(robots[a]) < get<3>(robots[b]);
        });

        for (auto& e : st) {
            result.push_back(get<1>(robots[e]));
        }

        return result;
    }
};