class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> cnt(101);

        for(auto &&num : nums) {
            cnt[num]++;
        }

        int sum = 0;
        for(auto &&c : cnt){
            if(c >= 2) sum += c * (c - 1) / 2;
        }

        return sum;
    }
};