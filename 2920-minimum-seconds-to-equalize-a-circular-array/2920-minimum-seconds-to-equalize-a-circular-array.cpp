class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        for(int i = 0, n = nums.size(); i < n; i++) {
            nums.push_back(nums[i]);
        }
        
        unordered_map<int, int> last;
        unordered_map<int, int> dp;
        
        for(int i = 0; i < nums.size() ; i++) {
            if(last.count(nums[i])) {
                dp[nums[i]] = max(dp[nums[i]], i - last[nums[i]]);
            }
            
            last[nums[i]] = i;
        }
        
        int mi = INT_MAX;
        for(auto &&[num, len] : dp) {
            if(len < mi) {
                mi = len;
            }
        }
        
        return floor(mi / 2.0);
    }
};