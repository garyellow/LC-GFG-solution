class Solution
{
public:
    Solution() {
        if (dp.empty()) {
            dp.push_back(vector<int>(1, 1));

            for (int i = 1; i <= 30; i++) {
                vector<int> temp(1, 1);

                for (int index = 1; index < dp.back().size(); index++)
                    temp.push_back(dp.back()[index - 1] + dp.back()[index]);

                temp.push_back(1);
                dp.push_back(temp);
            }
        }
    }

    vector<vector<int>> generate(int numRows) {
        return {dp.begin(), dp.begin() + numRows};
    }

    static vector<vector<int>> dp;
};

vector<vector<int>> Solution::dp;