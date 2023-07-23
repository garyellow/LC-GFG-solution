class Solution {
public:
    Solution()
    {
        if (dp.empty()) {
            dp.push_back({1});

            for (int i = 1; i <= 33; i++) {
                vector<int> temp({1});

                for (int index = 1; index < dp.back().size(); index++)
                    temp.push_back(dp.back()[index - 1] + dp.back()[index]);

                temp.push_back(1);
                dp.push_back(temp);
            }
        }
    }
    
    vector<int> getRow(int rowIndex) {
        return dp[rowIndex];
    }
    
    static vector<vector<int>> dp;
};

vector<vector<int>> Solution::dp;