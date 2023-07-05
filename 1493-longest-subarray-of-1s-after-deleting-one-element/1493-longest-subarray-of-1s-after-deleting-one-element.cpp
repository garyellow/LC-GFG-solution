class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0) == nums.size()) return nums.size() - 1;
        nums.push_back(0);
        
        queue<int> q({-1});
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) q.push(i);
            
            if(q.size() == 3) {
                ans = max(ans, i - q.front() - 2);
                q.pop();
            }
        }
        
        return ans;
    }
};