class Solution {
public:
    int numOfWays(vector<int>& nums) {
        return (countBST(nums) - 1) % int(1e9 + 7);
    }

    int countBST(vector<int>& nums) {
        if (nums.size() <= 2)
            return 1;

        vector<int> left, right;
        int root = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftCount = countBST(left);
        long long rightCount = countBST(right);
        long long totalCount = binomialCoefficient(left.size() + right.size(), left.size());

        return (leftCount * rightCount % int(1e9 + 7) * totalCount % int(1e9 + 7));
    }

    vector<vector<long long>> dp = vector<vector<long long>>(1001, vector<long long>(1001));
    long long binomialCoefficient(int n, int k) {
        if(!dp[n][k]) {
            dp[0][0] = 1;

            for (int i = 1; i <= n; i++) {
                dp[i][0] = 1;
                for (int j = 1; j <= min(i, k); j++) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % int(1e9 + 7);
                }
            }
        }

        return dp[n][k];
    }
};