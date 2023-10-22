class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = 0, mi = nums[k], mj = nums[k];
        for(int i = k, j = k; i != 0 || j != nums.size() - 1; ) {
            if(i == 0) j++;
            else if(j == nums.size() - 1) i--;
            else if(nums[i - 1] > nums[j + 1]) i--;
            else if(nums[i - 1] < nums[j + 1]) j++;
            else i--, j++;

            mi = min(mi, nums[i]);
            mj = min(mj, nums[j]);
            ans = max(ans, (j - i + 1) * min(mi, mj)); 
        }

        return max(ans, (int)nums.size() * min(mi, mj));
    }
};