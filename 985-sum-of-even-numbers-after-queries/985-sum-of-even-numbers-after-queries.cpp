class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {        
        int cnt = 0;
        
        for(auto &&num : nums)
            if(is_even(num)) cnt += num;
        
        vector<int> ans;
        for(auto &&num : queries)
        {
            if(is_even(nums[num.back()]))
                cnt -= nums[num.back()];
                
            nums[num.back()] += num.front();
                
            if(is_even(nums[num.back()]))
                cnt += nums[num.back()];
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
    
    inline bool is_even(const int &num)
    {
        return !(num & 1);
    }
};