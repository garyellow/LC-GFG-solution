class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = 0, r = 1e6;
        long long res1 = 0, res2 = 0;
        while(l < r) {
            long long m = l + ((r - l) / 2);
            res1 = 0, res2 = 0;
            
            for(int i = 0; i < nums.size(); i++) {
                res1 += abs(m - nums[i]) * cost[i];
                res2 += abs(m + 1 - nums[i]) * cost[i];
            }
            
            if(res2 > res1) r = m;
            else l = m + 1;
        }
        
        return min(res1, res2);
    }
};