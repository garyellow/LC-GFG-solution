class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        int prefix = 0;
        for(auto &&num : nums) {
            num = (prefix += num);
        }
        
        vector<int> ans;
        
        for(auto &&querie : queries) {
            ans.push_back(distance(nums.begin(), upper_bound(nums.begin(), nums.end(), querie)));
        }
        
        return ans;
    }
};