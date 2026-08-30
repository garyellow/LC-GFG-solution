class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        auto mi = ranges::min_element(nums);
        auto ma = ranges::max_element(nums);

        return min(
            {max(distance(nums.begin(), mi), distance(nums.begin(), ma)) + 1,
             max(distance(mi, nums.end()), distance(ma, nums.end())),
             distance(nums.begin(), mi) + distance(ma, nums.end()) + 1,
             distance(nums.begin(), ma) + distance(mi, nums.end()) + 1});
    }
};