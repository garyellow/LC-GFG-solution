class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int cnt = 1;
        for(int current = 0; current + nums[current] < nums.size() - 1; cnt++) {
            int can_go = current + nums[current], next_cango = 0;
            
            for(int j = current; j <= can_go; j++)
            {
                if(j + nums[j] > next_cango)
                {
                    next_cango = j + nums[j];
                    current = j;
                }  
            }
        }
        
        return cnt;
    }
};