class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int cnt = nums.front() > 0, cur = 1;
        for(; cur < nums.size(); cur++) {
            if(cur > nums[cur - 1] && cur < nums[cur]) {
                cnt++;
            }
        }
        
        cnt += nums.front() < cur;
        
        return cnt;
    }
};