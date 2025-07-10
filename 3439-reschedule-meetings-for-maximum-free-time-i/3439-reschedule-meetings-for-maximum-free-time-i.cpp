class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int cur = 0;
        vector<int> freeTime;
        for (int i = 0; i < startTime.size(); i++) {
            freeTime.emplace_back(startTime[i] - cur);
            cur = endTime[i];
        }

        freeTime.emplace_back(eventTime - cur);

        int temp =
            accumulate(freeTime.begin(),
                       freeTime.begin() + min(k + 1, int(freeTime.size())), 0);
        int result = temp;
        for (int i = 0; i + k + 1 < freeTime.size(); i++) {
            temp -= freeTime[i];
            temp += freeTime[i + k + 1];

            result = max(result, temp);
        }

        return result;
    }
};