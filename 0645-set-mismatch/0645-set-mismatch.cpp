class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int repeat, all = 0, cur = nums.front();
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == nums[i]) repeat = nums[i];
            all ^= i;
            cur ^= nums[i];
        }
        
        return {repeat, all ^ int(nums.size()) ^ repeat ^ cur};
    }
};