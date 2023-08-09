class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (cal(nums, mid, p)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

    bool cal(vector<int>& nums, int mid, int p) {
        int count = 0;
        for (int i = 1; i < nums.size() && count < p;) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        
        return count >= p;
    }
};