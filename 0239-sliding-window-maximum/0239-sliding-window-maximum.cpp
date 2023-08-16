class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> record;

        int i = 0;
        while(i < k - 1) {
            record[nums[i++]]++;
        }

        vector<int> ans;
        for(; i < nums.size(); i++) {
            record[nums[i]]++;
            ans.push_back(record.rbegin()->first);
            
            if(--record[nums[i - k + 1]] == 0) {
                record.erase(nums[i - k + 1]);
            }
        }

        return ans;
    }
};