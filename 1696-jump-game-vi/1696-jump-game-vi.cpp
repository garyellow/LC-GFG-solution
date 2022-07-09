class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> dp;
        int temp;
        for(int i = 0; i < nums.size(); i++)
        {
            while (!dp.empty() && dp.top().second < i - k) dp.pop();
            temp = nums[i] + (dp.empty() ? 0 : dp.top().first);
            dp.push({temp, i});
        }
        return temp;
    }
};