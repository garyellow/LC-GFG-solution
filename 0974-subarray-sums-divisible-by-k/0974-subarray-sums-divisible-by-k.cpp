class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k);
        
        nums[0] = (nums[0] % k + k) % k;
        cnt[nums[0]]++;
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = ((nums[i] + nums[i - 1]) % k + k) % k;
            cnt[nums[i]]++;
        }
        
        int ans = cnt[0];
        for(auto &&num : nums)
            ans += --cnt[num];
        
        return ans;
    }
};