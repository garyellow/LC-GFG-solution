class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (auto num : nums) {
            string s = to_string(num);
            for (auto ch : s) {
                result.push_back(ch - '0');
            }
        }

        return result;
    }
};