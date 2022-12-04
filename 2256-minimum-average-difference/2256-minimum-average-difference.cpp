class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long last = accumulate(nums.begin(), nums.end(), 0L);
        
        int ans = nums.size() - 1;
        int temp = last / nums.size();
        
        long sum = 0;
        for(int n = 1; nums.size() > 1; n++) {
            last -= nums.back();
            sum += nums.back();
            nums.pop_back();
            
            if(temp >= abs(last / long(nums.size()) - sum / n)){
                temp = abs(last / long(nums.size()) - sum / n);
                ans = nums.size() - 1;
            }
        }
        
        return ans;
    }
};