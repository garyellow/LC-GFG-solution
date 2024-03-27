class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;

        int i = 0, j = 0, tmp = 1, cnt = 0;

        while(i < nums.size()) {
            while(j < nums.size() && tmp * nums[j] < k) {
                tmp *= nums[j++];
            }

            cnt += j - i;
            if(i == j) {
                tmp = 1;
                i++;
                j++;
            }
            else tmp /= nums[i++];
        }

        return cnt;
    }
};