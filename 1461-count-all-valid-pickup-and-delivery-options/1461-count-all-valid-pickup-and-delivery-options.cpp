class Solution {
public:
    Solution() {
        for(long i = 1; i <= 500; i++) {
            dp.push_back(dp.back() * i * (2 * i - 1) % (int)(1e9 + 7));
        }
    }
    
    int countOrders(int n) {
        return dp[n];
    }
    
    static vector<int> dp;
};

vector<int> Solution::dp = vector<int>({1});

