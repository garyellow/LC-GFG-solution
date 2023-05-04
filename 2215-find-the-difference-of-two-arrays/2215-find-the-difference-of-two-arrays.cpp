class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        auto e1 = unique(nums1.begin(), nums1.end());
        
        sort(nums2.begin(), nums2.end());
        auto e2 = unique(nums2.begin(), nums2.end());
        
        vector<int> nums3, nums4;
        
        auto i1 = nums1.begin(), i2 = nums2.begin();
        
        while(i1 != e1 && i2 != e2) {
            if(*i1 == *i2) {
                i1++;
                i2++;
            }
            else if(*i1 < *i2) {
                nums3.push_back(*i1);
                i1++;
            }
            else if(*i1 > *i2) {
                nums4.push_back(*i2);
                i2++;
            }
        }
        
        while(i1 != e1) {
            nums3.push_back(*i1);
            i1++;
        }
        
        while(i2 != e2) {
            nums4.push_back(*i2);
            i2++;
        }
        
        return {nums3, nums4};
    }
};