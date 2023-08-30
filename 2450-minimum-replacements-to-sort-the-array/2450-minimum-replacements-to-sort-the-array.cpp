class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int cur = nums.back();
        for_each (nums.rbegin() + 1, nums.rend(), [&](auto num) {
            if(num > cur) {
                int cnt = ceil(1.0 * num / cur);
                ans += cnt - 1;
                cur = num / cnt;
            }
            cur = min(cur, num);
        });
        
        return ans;
    }
};