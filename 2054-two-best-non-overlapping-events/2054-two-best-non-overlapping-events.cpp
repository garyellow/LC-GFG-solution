class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        events.back().push_back(events.back()[2]);
        for (int i = events.size() - 2; i >= 0; i--) {
            events[i].push_back(max(events[i][2], events[i + 1][3]));
        }

        int maxSum = 0;
        for (int i = 0; i < events.size(); i++) {
            auto it = lower_bound(events.begin() + i + 1, events.end(), vector({events[i][1] + 1, 0, 0}));

            if (it != events.end()) {
                maxSum = max(maxSum, events[i][2] + it->at(3));
            }

            maxSum = max(maxSum, events[i][2]);
        }

        return maxSum;
    }
};