class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        nums.front() = (nums.front() % k + k) % k;
        
        for(int i = 1; i < nums.size(); i++)
            nums[i] = ((nums[i] + nums[i - 1]) % k + k) % k;
        
        vector<int> cnt(k);
        for(auto &&num : nums)
            cnt[num]++;
        
        int ans = 0;
        for(auto &&num : nums) {
            if(!num) ans++;
            ans += --cnt[num];
        }
        
        return ans;
    }
};