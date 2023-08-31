class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> range;

        for(int i = 0; i < ranges.size(); i++) {
            range.push_back({i - ranges[i], i + ranges[i]});
        }

        sort(range.begin(), range.end());

        int cnt = 0, choose = -1;
        for(int i = 0, cur = 0; cur < n && i < range.size(); ) {
            if(range[i].first <= cur) {
                choose = max(choose, range[i++].second);
                continue;
            }

            if(choose >= 0) {
                cur = choose;
                cnt++;
                choose = -1;
            }
            else {
                return -1;
            }
        }

        return choose >= 0 ? (choose >= n ? cnt + 1 : -1) : cnt ;
    }
};