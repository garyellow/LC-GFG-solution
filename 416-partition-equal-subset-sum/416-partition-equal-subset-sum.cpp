class Solution {
public:
    vector<bool> dp = vector<bool>(10101, false);
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        
        if(sum & 1) return false;
        else return bt(nums, nums.size() - 1, 0, sum / 2);
    }
    
    bool bt(vector<int> nums, int index, int now, const int half)
    {
        if(now == half)
            return true;
        else if(dp[now] == 0 && now < half)
        {
            for(int i = index - 1; i >= 0; i--)
            {
                if(bt(nums, i, now + nums[i], half)) return true;
                else dp[now] = true;
            }
        }
        return false;
    }
};