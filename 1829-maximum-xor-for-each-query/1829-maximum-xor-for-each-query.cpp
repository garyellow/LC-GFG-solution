class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int target = pow(2, maximumBit) - 1;

        int temp = accumulate(nums.begin(), nums.end(), 0,
                              [](auto sum, auto& x) { return sum ^ x; });

        vector<int> ans;
        while (!nums.empty()) {
            ans.push_back(temp ^ target);
            temp ^= nums.back();
            nums.pop_back();
        }

        return ans;
    }
};