class Solution {
    static vector<int> dp;

public:
    Solution() {
        if (dp.empty()) {
            vector<int> temp;
            dp = temp = vector<int>(1e4 + 1, 0);

            int count = 0;

            for (int i = 0; i <= 1e4; i++) {
                if (i < 10) {
                    if (i == 0 || i == 1 || i == 8) {
                        temp[i] = 1;
                    } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                        temp[i] = 2;
                        count++;
                    } else {
                        temp[i] = 0;
                    }
                } else {
                    int a = temp[i / 10];
                    int b = temp[i % 10];

                    if (a == 1 && b == 1) {
                        temp[i] = 1;
                    } else if (a >= 1 && b >= 1) {
                        temp[i] = 2;
                        count++;
                    } else {
                        temp[i] = 0;
                    }
                }

                dp[i] = count;
            }
        }
    }

    int rotatedDigits(int n) { return dp[n]; }
};

vector<int> Solution::dp;