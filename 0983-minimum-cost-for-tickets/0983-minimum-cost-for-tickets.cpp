class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> last7, last30;
        int cost = 0;

        for (auto &&day : days) {
            while (last7.size() && last7.front().first + 7 <= day) last7.pop();
            while (last30.size() && last30.front().first + 30 <= day) last30.pop();

            last7.push({ day, cost + costs[1] });
            last30.push({ day, cost + costs[2] });

            cost = min({ cost + costs[0], last7.front().second, last30.front().second });
        }
        
        return cost;
    }
};