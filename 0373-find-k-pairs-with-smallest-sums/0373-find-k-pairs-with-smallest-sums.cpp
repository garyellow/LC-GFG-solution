class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        vector<vector<int>::iterator> cache(nums1.size(), nums2.begin());
        
        auto cmp = [&](vector<int> &x, vector<int> &y) { return x[0] + x[1] >= y[0] + y[1]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        
        for(int i = 0; i < nums1.size(); i++) {
            heap.push({nums1[i], *cache[i], i});
        }
        
        while(ans.size() < k && heap.size()) {
            ans.push_back({heap.top()[0], heap.top()[1]});
            
            int i = heap.top()[2];
            if (++cache[i] != nums2.end()) {
                heap.push({nums1[i], *cache[i], i});
            }
            
            heap.pop();
        }
        
        return ans;
    }
};