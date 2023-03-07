class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e15;
        
        while(l < r) {
            long long mid = (l + r) / 2;
            
            if(count(time, mid) < totalTrips) l = mid + 1;
            else r = mid;
        }
        
        return r;
    }
    
    int count(vector<int>& time, long long trips) {
        long long cnt = 0;
        
        for(auto &&t : time) {
            cnt += trips / t;
            if(cnt > INT_MAX) return INT_MAX;
        }
        
        return cnt;
    }
}; 