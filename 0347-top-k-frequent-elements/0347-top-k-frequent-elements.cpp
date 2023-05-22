class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        
        for(auto &&i : nums)
            cnt[i]++;
        
        auto cmp = [](pair<int, int> x, pair<int, int> y){ return x.second < y.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        
        for(auto &&i : cnt)
            heap.push(i);
        
        vector<int> ans;
        while(k--) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        
        return ans;
    }
};