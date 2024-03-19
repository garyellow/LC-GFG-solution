class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto&& task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.rbegin(), freq.rend());

        int maxVal = freq.front() - 1;
        int idleTime = maxVal * n;

        for (int i = 1; i < 26; ++i) {
            idleTime -= min(maxVal, freq[i]);
        }

        if (idleTime > 0)
            return tasks.size() + idleTime;
        else
            return tasks.size();
    }
};