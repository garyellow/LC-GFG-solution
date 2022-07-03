class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int all = nums1.size() + nums2.size();
        vector<int> save(all);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), save.begin());
        
        return all & 1 ? save[all / 2] : (save[all / 2 - 1] + save[all / 2]) / 2.0;
    }
};