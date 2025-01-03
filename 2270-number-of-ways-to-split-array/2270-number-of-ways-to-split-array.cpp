class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long leftSum = nums.front(),
            rightSum = accumulate(nums.begin() + 1, nums.end(), 0LL);

        int valid = leftSum >= rightSum;

        for (int i = 1; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum)
                valid++;
        }

        return valid;
    }
};