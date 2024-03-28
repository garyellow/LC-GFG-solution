class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int over = 0, l = 0, r = 0, ans = 0;
        unordered_map<int, int> record;
        
        while(r < nums.size()) {
            if(over && --record[nums[l++]] == k) over--;
            else if(++record[nums[r++]] == k + 1) over++;
            
            if(!over) ans = max(ans, r - l);
        }
        
        return ans;
    }
};