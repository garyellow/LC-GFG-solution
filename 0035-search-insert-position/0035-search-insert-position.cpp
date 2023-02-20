#include <cmath>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
//         int right = 0, left = nums.size() - 1;
            
//         if(nums.at(right) > target)
//             return right;
//         else if(nums.at(left) < target)
//             return left + 1;
        
//         while(true)
//         {
//             float half = (float)(left + right) / 2;
            
//             if(nums.at(floor(half)) == target)
//                 return floor(half);
            
//             else if(nums.at(floor(half)) <= target && nums.at(ceil(half)) >= target)
//                 return ceil(half);
            
//             else if(nums.at(floor(half)) > target)
//             {
//                 if(nums.at(floor(half) - 1) < target)
//                     return floor(half);
                
//                 left = floor(half);
//             }
//             else if(nums.at(ceil(half)) < target)
//             {
//                 if(nums.at(ceil(half) + 1) >= target)
//                     return ceil(half) + 1;
                
//                 right = ceil(half);
//             }
                
//         }
        
    }
};