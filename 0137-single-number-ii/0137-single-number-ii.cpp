class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        
        for(auto &i : nums)
            cnt[i]++;
        
        for(auto &[c, time] : cnt)
            if(time == 1) return c;
        
        return 0;
    }
};