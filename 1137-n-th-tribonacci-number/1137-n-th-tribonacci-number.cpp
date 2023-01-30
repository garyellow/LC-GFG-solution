class Solution {
public:
    static vector<int> dp;
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(!dp[n]) dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};

vector<int> Solution::dp = vector<int>(38);