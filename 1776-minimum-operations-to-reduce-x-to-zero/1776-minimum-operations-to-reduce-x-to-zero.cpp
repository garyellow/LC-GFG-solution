class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r = nums.size() - 1;
        int l_cnt = 0, r_cnt = 0;
        
        for(; l < nums.size() && x > 0; l++, l_cnt++)
            x -= nums[l];
        
        int ans = INT_MAX;
        while(l >= 0 && r >= 0) {
            if(x <= 0) {
                if(x == 0) ans = min(ans, l_cnt + r_cnt);
                if(l == 0) break;
                x += nums[--l];
                l_cnt--;
            }
            else {
                x -= nums[r--];
                r_cnt++;
            }
        }
        
        return ans > nums.size() ? -1 : ans;
    }
};