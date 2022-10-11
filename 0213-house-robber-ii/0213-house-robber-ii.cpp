class Solution {
public:
    int rob(vector<int>& nums) {
        int save, save2, cur1 = 0, cur2 = 0;
        
        if(nums.size() == 1)
            return nums.front();
        
        save = save2 = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            cur1 = max(save, nums[i] + save2);
            save2 = save;
            save = cur1;
        }
        
        save = save2 = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            cur2 = max(save, nums[i] + save2);
            save2 = save;
            save = cur2;
        }
        
        return max(cur1, cur2);
    }
};