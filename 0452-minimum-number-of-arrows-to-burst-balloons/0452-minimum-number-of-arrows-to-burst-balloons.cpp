class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt = 0;
        while(points.size())
        {
            auto it = points.rbegin() - 1;
            while(++it != points.rend() && points.back().front() <= it->back());
            int num = it - points.rbegin();
            while(num--) points.pop_back();
            cnt++;
        }
        return cnt;
    }
};