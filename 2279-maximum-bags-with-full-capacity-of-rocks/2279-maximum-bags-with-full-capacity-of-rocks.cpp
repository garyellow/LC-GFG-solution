class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i = 0; i < capacity.size(); i++)
            capacity[i] -= rocks[i];
        
        sort(capacity.begin(), capacity.end());
        
        int cnt = 0;
        for(auto &&r : capacity) {
            if(additionalRocks >= 0) {
                additionalRocks -= r;
                cnt++;
            }
        }
        
        return cnt - !(additionalRocks >= 0);
    }
};