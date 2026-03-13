class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<vector<long long>, vector<vector<long long>>,
                       greater<vector<long long>>>
            pq;

        for (auto workerTime : workerTimes) {
            pq.push({workerTime, 1, workerTime});
        }

        long long m = 0;
        while (mountainHeight--) {
            auto worker = pq.top();
            pq.pop();

            m = max(m, worker[0]);

            worker[1]++;
            pq.push({worker[0] + worker[1] * worker[2], worker[1], worker[2]});
        }

        return m;
    }
};