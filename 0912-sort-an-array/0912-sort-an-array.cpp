class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> heap(nums.begin(), nums.end());
        
        while(heap.size()) {
            nums[heap.size() - 1] = heap.top();
            heap.pop();
        }
        
        return nums;
    }
};