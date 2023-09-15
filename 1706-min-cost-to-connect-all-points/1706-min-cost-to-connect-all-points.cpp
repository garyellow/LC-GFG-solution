class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto cmp = [&](pair<int, int> &i, pair<int, int> &j) {
            int ii = manhattan(i.first, i.second, points);
            int jj = manhattan(j.first, j.second, points);
            return ii > jj;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                heap.push({i, j});
            }
        }

        vector<int> u(points.size());
        iota(u.begin(), u.end(), 0);

        int finish = points.size() - 1, cnt = 0;
        while(finish) {
            auto [x, y] = heap.top();
            heap.pop();

            if(checkFriend(x, y, u)) continue;

            makeFriend(x, y, u);
            cnt += manhattan(x, y, points);
            finish--;
        }

        return cnt;
    }

    int manhattan(int i, int j, vector<vector<int>>& points) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }

    void makeFriend(int i, int j, vector<int> &u) {
        u[find(i, u)] = find(j, u);
    }

    bool checkFriend(int i, int j, vector<int> &u) {
        return find(i, u) == find(j, u);
    }

    int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};