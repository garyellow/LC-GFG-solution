class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = '1' - (nums[i][i] - '0');
        }

        return ans;
    }
};