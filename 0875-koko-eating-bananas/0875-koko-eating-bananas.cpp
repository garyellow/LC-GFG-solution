class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while(l < r) {
            int mid = (l + r) / 2;
            if(calculate(mid, piles) > h) l = mid + 1;
            else r = mid;
        }
            
        return l;
    }
    
    int calculate(double num, vector<int> &piles) {
        return accumulate(piles.begin(), piles.end(), 0, [&](int &sum, int &val) { return sum + ceil(val / num); });
    }
};