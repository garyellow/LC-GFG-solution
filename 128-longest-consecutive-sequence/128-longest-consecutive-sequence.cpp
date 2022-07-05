class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++)
            nums[i - 1] = nums[i] - nums[i - 1];
        
        nums.pop_back();
        
        int cnt = 0, ans = 0;
        for(auto &&i :nums)
        {
            if(i == 1) ans = max(ans, ++cnt);
            else if(i > 1) cnt = 0;
        }
        
        return ans + 1;
    }
};