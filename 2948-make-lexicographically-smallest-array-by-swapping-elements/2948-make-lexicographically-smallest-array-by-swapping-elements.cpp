class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        ranges::sort(sorted);
        vector<vector<int>> grps;
        unordered_map<int, int> map;
        int id = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                grps.push_back({});
                id++;
            }
            grps[id].push_back(sorted[i]);
            map[sorted[i]] = id;
        }

        vector<int> idx(grps.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int cur = map[nums[i]];
            nums[i] = grps[cur][idx[cur]];
            idx[cur]++;
        }

        return nums;
    }
};