class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums.front() != nums[nums.front()])
            swap(nums.front(), nums[nums.front()]);
        
        return nums.front();
    }
};