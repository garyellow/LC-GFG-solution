class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size());

        for (int i = 0; i < arr.size(); i++)
            dfs(i, dp, arr, d);

        return *ranges::max_element(dp);
    }

    int dfs(int index, vector<int>& dp, const vector<int>& arr, int d) {
        if (dp[index] == 0) {
            int temp = 0;
            for (int i = index - 1;
                 i >= index - d && i >= 0 && arr[index] > arr[i]; i--)
                temp = max(temp, dfs(i, dp, arr, d));

            for (int i = index + 1;
                 i <= index + d && i < arr.size() && arr[index] > arr[i]; i++)
                temp = max(temp, dfs(i, dp, arr, d));

            dp[index] = 1 + temp;
        }

        return dp[index];
    }
};