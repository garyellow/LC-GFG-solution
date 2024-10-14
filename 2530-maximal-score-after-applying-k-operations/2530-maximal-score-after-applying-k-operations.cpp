class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> heap(nums.begin(), nums.end());

        while(k--) {
            auto cur = heap.top();
            heap.pop();

            ans += cur;
            heap.push(ceil(cur / 3.0));
        }

        return ans;
    }
};