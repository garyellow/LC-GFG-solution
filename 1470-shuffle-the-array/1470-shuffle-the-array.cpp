class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        bool flag = true;
        inplace_merge(nums.begin(), nums.begin() + n, nums.end(), [&](auto &x, auto &y){
            return flag = !flag;
        });
        return nums;
    }
};