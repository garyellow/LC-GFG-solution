class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> saved;
        int result = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++) {
            if (saved.count(nums[i])) {
                result = min(result, i - saved[nums[i]]);
            }

            string tmp = to_string(nums[i]);
            ranges::reverse(tmp);

            saved[stoi(tmp)] = max(saved[stoi(tmp)], i);
        }

        return result == numeric_limits<int>::max() ? -1 : result;
    }
};