class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cnt = 0, ans = cnt;
        
        for(auto &&g : gain) {
            ans = max(ans, cnt += g);
        }
        
        return ans;
    }
};