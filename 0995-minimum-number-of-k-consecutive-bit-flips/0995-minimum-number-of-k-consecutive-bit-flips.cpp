class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > nums.size()) {
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                ++res;
            }
        }

        return res;
    }
};