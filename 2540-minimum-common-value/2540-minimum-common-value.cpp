class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(min(nums1.size(), nums2.size()));
        auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), temp.begin());

        return it - temp.begin() ? temp.front() : -1;
    }
};