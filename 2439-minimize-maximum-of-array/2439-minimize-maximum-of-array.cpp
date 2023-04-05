class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0;
        long result = 0;
        
        for (int index = 0; index < nums.size(); index++) {
            sum += nums[index];
            result = max(result, long(ceil(1.0 * sum / (index + 1))));
        }
        
        return result;
    }
};