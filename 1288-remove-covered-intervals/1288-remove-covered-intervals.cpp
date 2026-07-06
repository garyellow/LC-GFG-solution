class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        vector<bool> exist(intervals.size(), true);

        int cnt = 0;
        for (int i = 0, step, equal; i < intervals.size(); i++) {
            if (exist[i] == false)
                continue;

            for (step = 1, equal = 0; i + step < intervals.size(); step++) {
                if (exist[i + step] == false)
                    continue;

                if (intervals[i + step].back() <= intervals[i].back()) {
                    cnt++;
                    exist[i + step] = false;
                } else if ((intervals[i + step].front() ==
                                intervals[i].front() &&
                            intervals[i + step].back() > intervals[i].back()))
                    cnt++;
                else
                    break;
            }
        }

        return intervals.size() - cnt;
    }
};