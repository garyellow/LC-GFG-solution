class Solution {
public:
    int rob(vector<int>& nums) {
        int save2 = 0, save = 0, cur = 0;
        
        for(auto &&i : nums)
        {
            cur = max(save, i + save2);
            save2 = save;
            save = cur;
        }
        
        return cur;
    }
};