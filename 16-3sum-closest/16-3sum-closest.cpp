class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long ans = INT_MAX;
        for(int middle = 1; middle < nums.size() - 1; middle++) {
            int front = middle - 1, back = middle + 1;
            int cur = nums[front] + nums[middle] + nums[back];
            if(abs(cur - target) < abs(ans - target))
                ans = cur;
            
            while(front > 0 && back < nums.size() - 1) {
                if(cur == target) return target;
                else if(cur < target) {
                    cur -= nums[back++];
                    cur += nums[back];
                }
                else {
                    cur -= nums[front--];
                    cur += nums[front];
                }
                
                if(abs(cur - target) < abs(ans - target))
                    ans = cur;
            }
        }
        
        return ans;
    }
};