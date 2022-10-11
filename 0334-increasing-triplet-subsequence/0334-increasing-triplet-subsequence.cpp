class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long x, y, z;
        x = y = z = INT_MAX + 1L;
        
        for(auto &&num : nums)
        {
            if(num <= x) x = num;
            else if(num <= y) y = num;
            else if(num <= z) z = num;
        }
        
        return z != INT_MAX + 1L;
    }
};