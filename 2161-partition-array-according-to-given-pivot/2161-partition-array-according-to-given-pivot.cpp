class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low, high;
        int cnt = 0;

        for (auto& num : nums) {
            if (num == pivot) {
                cnt++;
            } else if (num < pivot) {
                low.emplace_back(num);
            } else if (num > pivot) {
                high.emplace_back(num);
            }
        }

        while (cnt--) {
            low.emplace_back(pivot);
        }

        for (auto temp : high) {
            low.emplace_back(temp);
        }

        return low;
    }
};