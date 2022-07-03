class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        
        vector<int> check(nums.size() - 1);
        
        for(int i = 0; i < check.size(); i++)
        {
            if(nums[i] > nums[i + 1]) check[i] = 2;
            else if(nums[i] < nums[i + 1]) check[i] = 1;
        }
        
        int cnt1 = 0, cnt2 = 0, last = 1;
        for(auto &&i : check)
        {
            if(i && last != i)
            {
                cnt1++;
                last = i;
            }
        }
        
        last = 2;
        for(auto &&i : check)
        {
            if(i && last != i)
            {
                cnt2++;
                last = i;
            }
        }
        
        return max(cnt1, cnt2) + 1;
    }
};