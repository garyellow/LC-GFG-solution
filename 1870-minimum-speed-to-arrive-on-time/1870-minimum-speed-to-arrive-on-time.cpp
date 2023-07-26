class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e9 + 1;
        
        while(l < r) {
            int mid = (l + r) / 2;
            
            if(cal(dist, hour, mid)) r = mid;
            else l = mid + 1;
        }
        
        return l == 1e9 + 1 ? -1 : l;
    }
    
    bool cal(vector<int>& dist, double hour, double target) {
        double ans = 0;
        
        for(int i = 0; i < dist.size() - 1; i++) {
            ans += ceil(dist[i] / target);
        }
        
        ans += dist.back() / target;
        
        return ans <= hour;
    }
};