class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices.front(), ans = 0;
        
        for(auto &&i : prices) {
            if(i >= cur_min) ans = max(ans, i - cur_min);
            else cur_min = i;
        }
        
        return ans;
    }
};