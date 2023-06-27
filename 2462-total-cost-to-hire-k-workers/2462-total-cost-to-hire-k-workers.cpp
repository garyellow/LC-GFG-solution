class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        int cnt = 0, l = 0, r = costs.size() - 1;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lh, rh;
        
        for(; lh.size() < candidates && l != costs.size(); l++) {
            lh.push({costs[l], l});
        }
        
        for(; rh.size() < candidates && r != -1; r--) {
            rh.push({costs[r], r});
        }
        
        while(cnt < k) {
            if(lh.top() < rh.top()) {
                cost += lh.top().first;
                costs[lh.top().second] = INT_MAX;
                cnt++;
                
                lh.pop();
                if(l != costs.size()){
                    lh.push({costs[l], l});
                    l++;
                }
            }
            else if(lh.top() > rh.top()) {
                cost += rh.top().first;
                costs[rh.top().second] = INT_MAX;
                cnt++;
                
                rh.pop();
                if(r != -1) {
                    rh.push({costs[r], r});
                    r--;
                }
            }
            else {
                cost += lh.top().first;
                costs[lh.top().second] = INT_MAX;
                cnt++;
                
                lh.pop();
                if(l != costs.size()){
                    lh.push({costs[l], l});
                    l++;
                }
                
                rh.pop();
                if(r != -1) {
                    rh.push({costs[r], r});
                    r--;
                }
            }
        }
        
        return cost;
    }
};