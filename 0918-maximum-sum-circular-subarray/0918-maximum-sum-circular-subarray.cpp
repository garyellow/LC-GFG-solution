class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_s = INT_MAX, min_c = 0, max_s = INT_MIN, max_c = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            min_c += nums[i];
            max_c += nums[i];
            
            min_s = min(min_s, min_c);
            max_s = max(max_s, max_c);
            
            if(min_c > 0) min_c = 0;
            if(max_c < 0) max_c = 0;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);

        return sum == min_s ? max_s : max(sum - min_s, max_s);
    }
};