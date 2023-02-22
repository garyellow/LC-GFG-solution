class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = INT_MAX - l;
      
        while(l < r) {
            int half = (l + r) / 2;
            
            if(possible(half, days, weights))  r = half;
            else l = half + 1;
        }
        
        return r;
    }
    
    bool possible(int capacity, int days, vector<int>& weights) {
        int cur = 0, cnt = 1;
        for(auto &&weight : weights) {
            
            if(cur + weight > capacity) {
                cnt++;
                cur = 0;
            }
            
            cur += weight;
        }
        
        return days >= cnt;
    }
};