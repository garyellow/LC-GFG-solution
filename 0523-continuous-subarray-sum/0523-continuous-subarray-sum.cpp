class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cur = nums.front() % k;
        bool last = false;
        set<int> mod({cur});
        
        for(int i = 1; i < nums.size(); i++) {
            cur = (cur + nums[i]) % k;
            if(nums[i] % k ? (cur == 0 || mod.find(cur) != mod.end()) : nums[i - 1] % k == 0) return true;
            mod.insert(cur);
        }
        
        return false;
    }
};