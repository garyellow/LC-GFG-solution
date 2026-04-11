class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, array<int, 3>> arrs;
        int result = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++) {
            if (!arrs.count(nums[i])) {
                arrs[nums[i]].fill(-1);
            }

            if (arrs[nums[i]][0] == -1) {
                arrs[nums[i]][0] = i;
            } else if (arrs[nums[i]][1] == -1) {
                arrs[nums[i]][1] = i;
            } else if (arrs[nums[i]][2] == -1) {
                arrs[nums[i]][2] = i;
                result = min(result, 2 * (i - arrs[nums[i]][0]));
            } else {
                arrs[nums[i]][0] = arrs[nums[i]][1];
                arrs[nums[i]][1] = arrs[nums[i]][2];
                arrs[nums[i]][2] = i;
                result = min(result, 2 * (i - arrs[nums[i]][0]));
            }
        }

        return result == numeric_limits<int>::max() ? -1 : result;
    }
};