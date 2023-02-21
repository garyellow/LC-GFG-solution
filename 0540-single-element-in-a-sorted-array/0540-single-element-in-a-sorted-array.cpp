class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size();
        
        if(nums.size() >= 2) {
            while(l < r) {
                int index = (l + r) / 2;
                index -= index & 1;

                if(nums[index] != nums[index + 1]) r = index;
                else l = index + 2;
            }
        }
        
        return nums[l];
    }
};