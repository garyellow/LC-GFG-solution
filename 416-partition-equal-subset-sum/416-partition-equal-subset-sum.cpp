class Solution {
public:
    vector<bool> dp = vector<bool>(10101);
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum & 1) return false;
        else return bt(nums, 0, 0, sum / 2);
    }
    
    bool bt(const vector<int> &nums, int index, int now, const int &half)
    {
        if(now == half)
            return true;
        else if(dp[now] == 0 && now < half)
        {
            for(int i = index + 1, len = nums.size(); i < len; i++)
            {
                if(bt(nums, i, now + nums[i], half)) return true;
                else dp[now] = true;
            }
        }
        return false;
    }
};