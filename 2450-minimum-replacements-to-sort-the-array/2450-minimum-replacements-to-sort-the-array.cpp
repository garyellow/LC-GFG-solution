class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int cur = nums.back();
        long long ans = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            cout << cur << endl;
            int temp = nums[i];
            if(temp > cur) {
                int cnt = ceil(1.0 * temp / cur);
                ans += cnt - 1;
                cur = temp / cnt;
            }
            cur = min(cur, temp);
        }

        return ans;
    }
};