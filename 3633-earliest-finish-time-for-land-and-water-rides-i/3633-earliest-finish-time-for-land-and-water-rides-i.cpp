class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int minL = 3000, minW = minL, res = minW;
        int n = landStartTime.size(), m = waterStartTime.size();

        for (int i = 0; i < n; i++)
            minL = min(minL, landStartTime[i] + landDuration[i]);

        for (int i = 0; i < m; i++) {
            minW = min(minW, waterStartTime[i] + waterDuration[i]);
            res = min(res, max(minL, waterStartTime[i]) + waterDuration[i]);
        }

        for (int i = 0; i < n; i++) {
            res = min(res, max(minW, landStartTime[i]) + landDuration[i]);
        }

        return res;
    }
};