class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        
        for(int i = 0; i < nums.size(); i++) {
            if(record.count(nums[i]) && i - record[nums[i]] <= k) return true;
            record[nums[i]] = i;
        }
        
        return false;
    }
};