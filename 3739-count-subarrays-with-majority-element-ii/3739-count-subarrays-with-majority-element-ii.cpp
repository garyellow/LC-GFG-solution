class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        vector<int> pref(nums.size());
        pref[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i - 1] + nums[i];
        }

        int shift = nums.size();
        vector<int> freq(2 * nums.size() + 1, 0);

        freq[shift] = 1;

        long long valid = 0;
        int lastSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pref[i] > lastSum) {
                valid += freq[lastSum + shift];
            } else {
                valid -= freq[pref[i] + shift];
            }

            cnt += valid;
            freq[pref[i] + shift]++;
            lastSum = pref[i];
        }

        return cnt;
    }
};