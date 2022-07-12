class Solution {
public:
    vector<bool> dp = vector<bool>(20001, false);
    vector<bool> used = vector<bool>(201, false);
    int half;
    bool check = false;
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        if(sum & 1)
            return false;
        else
        {
            half = sum / 2;
            return bt(nums, 0, 0);
        }
        
    }
    
    bool bt(vector<int> nums, int now, int index)
    {
        if(check || now == half)
        {
            check = true;
            return true;
        }
        else if(dp[now] || now > half)
        {
            dp[now] = true;
            return false;
        }
        else
        {
            for(int i = index, len = nums.size(); i < len; i++)
            {
                if (!used[i])
                {
                    used[i] = true;
                    bt(nums, now + nums[i], i);
                    used[i] = false;
                }
                
                if(check)
                    return true;
                else
                    dp[now] = true;
            }
            
            return false;
        }
    }
};