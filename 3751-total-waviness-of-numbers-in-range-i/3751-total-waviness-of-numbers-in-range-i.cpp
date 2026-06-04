class Solution {
    static vector<int> dp, pref;

public:
    Solution() {
        if (pref.empty()) {
            dp.resize(100001);
            pref.resize(100001);

            for (int i = 100; i < 100001; i++) {
                int r = i % 10;
                int m = (i / 10) % 10;
                int l = (i / 100) % 10;

                bool isWave = (m > max(l, r)) | (m < min(l, r));
                dp[i] = dp[i / 10] + isWave;
                pref[i] = pref[i - 1] + dp[i];
            }
        }
    }

    int totalWaviness(int num1, int num2) {
        return pref[num2] - pref[num1 - 1];
    }
};

vector<int> Solution::dp, Solution::pref;