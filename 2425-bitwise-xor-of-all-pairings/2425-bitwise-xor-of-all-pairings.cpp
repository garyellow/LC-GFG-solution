class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> nums3;

        if (nums2.size() % 2 == 1) {
            for (const auto& num : nums1) {
                nums3[num] = !nums3[num];
            }
        }

        if (nums1.size() % 2 == 1) {
            for (const auto& num : nums2) {
                nums3[num] = !nums3[num];
            }
        }

        int result = 0;
        for (const auto& [num, odd] : nums3) {
            if (odd) {
                result ^= num;
            }
        }

        return result;
    }
};