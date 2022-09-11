class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers;
        
        for(int i = 0; i < n; i++)
            engineers.push_back({efficiency[i], speed[i]});
        
        sort(engineers.rbegin(), engineers.rend());
        
        priority_queue<int, vector<int>, greater<int>> heap;
        long min_eff, cnt = 0, max_per = INT_MIN;
        
        for(auto &&[eff, spe] : engineers) {
            min_eff = eff;
            cnt += spe;
            heap.push(spe);
            
            if(heap.size() > k) {
                cnt -= heap.top();
                heap.pop();
            }
                
            max_per = max(max_per, min_eff * cnt);
        }
        
        return max_per % int(1e9 + 7);
    }
};