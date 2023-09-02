class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<pair<int, int>> st;

        for(int i = 0; i < 2 * nums.size(); i++) {
            int index = i % nums.size();

            while(st.size() && nums[index] > st.top().first) {
                if(ans[st.top().second] == -1) ans[st.top().second] = nums[index];
                st.pop();
            }

            st.push({nums[index], index});
        }

        return ans;
    }
};