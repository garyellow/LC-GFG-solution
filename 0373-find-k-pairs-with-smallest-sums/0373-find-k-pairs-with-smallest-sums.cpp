class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        auto cmp = [&](pair<int, vector<int>::iterator> &x, pair<int, vector<int>::iterator> &y) { return x.first + *x.second > y.first + *y.second; };
        priority_queue<pair<int, vector<int>::iterator>, vector<pair<int, vector<int>::iterator>>, decltype(cmp)> heap(cmp);
        
        for(int i = 0; i < nums1.size(); i++) {
            heap.push({nums1[i], nums2.begin()});
        }
        
        while(ans.size() < k && heap.size()) {
            auto [num, index] = heap.top();
            ans.push_back({num, *index});
            
            if (++index != nums2.end()) {
                heap.push({num, index});
            }
            
            heap.pop();
        }
        
        return ans;
    }
};