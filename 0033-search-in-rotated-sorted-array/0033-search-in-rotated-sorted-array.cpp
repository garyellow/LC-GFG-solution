class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) == nums.end() ? -1 : distance(nums.begin(), find(nums.begin(), nums.end(), target));
    }
};