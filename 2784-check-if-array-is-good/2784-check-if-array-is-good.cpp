class Solution {
public:
    bool isGood(vector<int>& nums) {
        int mx = *ranges::max_element(nums);

        if (nums.size() != mx + 1)
            return false;

        vector<int> freq(mx + 1, 0);

        for (auto x : nums) {
            if (x < 1 || x > mx)
                return false;
            freq[x]++;
        }

        for (int i = 1; i < mx; i++) {
            if (freq[i] != 1)
                return false;
        }

        return freq[mx] == 2;
    }
};