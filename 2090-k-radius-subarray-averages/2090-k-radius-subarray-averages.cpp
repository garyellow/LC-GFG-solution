class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long sum = 0;
        
        while (r < nums.size() && r <= 2 * k) {
            sum += nums[r++];
        }
        
        vector<int> ans(nums.size(), -1);
        
        for(int m = k; m < int(nums.size()) - k; m++) {
            ans[m] = sum / (2 * k + 1);
            sum -= nums[l++];
            if (r < nums.size()) sum += nums[r++];
        }
        cout << 2;
        
        return ans;
    }
};