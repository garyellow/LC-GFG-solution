class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> save;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if (save.find(target - nums[i]) != save.end())
                return {save[target - nums[i]], i};
            
            save[nums[i]] = i;
        }
        
        return {};
    }
};