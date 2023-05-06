class Solution {
public:
    static vector<int> pow;
    
    Solution() {
        if(pow.empty()) {
            pow.push_back(1);
            
            for(int i = 1; i < 1e5; i++)
                pow.push_back((pow.back() << 1) % int(1e9 + 7));
        }
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long ans = 0;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pow[r - l]) % int(1e9 + 7);
                l++;
            } 
            else r--;
        }
        return ans % int(1e9 + 7);
    }
};

vector<int> Solution::pow;