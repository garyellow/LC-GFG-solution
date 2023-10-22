class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        for(int i = k, m = nums[k]; i >= 0; i--) m = nums[i] = min(m, nums[i]);
        for(int i = k, m = nums[k]; i < nums.size(); i++) m = nums[i] = min(m, nums[i]);

        int ans = nums.size() * min(nums.front(), nums.back());
        for(int i = k, j = k; i != 0 || j != nums.size() - 1; ) {
            if(i == 0) j++;
            else if(j == nums.size() - 1) i--;
            else if(nums[i - 1] > nums[j + 1]) i--;
            else if(nums[i - 1] < nums[j + 1]) j++;
            else i--, j++;

            ans = max(ans, (j - i + 1) * min(nums[i], nums[j]));
        }

        return ans;
    }
};