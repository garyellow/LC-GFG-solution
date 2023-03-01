class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> hash;
        
        for(auto &&num : nums) {
            hash[num]++;
        }
        
        vector<int> ans;
        
        for(auto &&[num, cnt] : hash) {
            while(cnt--) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};