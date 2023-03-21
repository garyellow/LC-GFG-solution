class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        
        long long cur = 0;
        
        for(auto &&i : nums) {
            if(i) {
                cnt += cal(cur);
                cur = 0;
            }
            else cur++;
        }
        
        return cnt + cal(cur);
    }
    
    inline long long cal(long long val) {
        return (1 + val) * val / 2;
    } 
};