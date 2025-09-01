class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto& c : classes) {
            pq.push({1.0 * (c[0] + 1) / (c[1] + 1) - 1.0 * c[0] / c[1],
                     {c[0], c[1]}});
        }

        while (pq.size() && extraStudents--) {
            auto [_, c] = pq.top();
            pq.pop();

            auto [pass, all] = c;
            pass++, all++;
            pq.push(
                {1.0 * (pass + 1) / (all + 1) - 1.0 * pass / all, {pass, all}});
        }

        double sum = 0;
        while (pq.size()) {
            auto [_, c] = pq.top();
            pq.pop();

            auto [pass, all] = c;
            sum += 1.0 * pass / all;
        }

        return sum / classes.size();
    }
};