class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, result = 0;
        for (int j = 0; j < nums2.size(); j++) {
            while (i < nums1.size() && i < j && nums1[i] > nums2[j]) {
                i++;
            }

            if (i < nums1.size()) {
                result = max(result, j - i);
            }
        }

        return result;
    }
};