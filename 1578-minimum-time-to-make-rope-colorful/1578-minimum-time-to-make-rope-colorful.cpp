class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        int cost = 0;
        
        int sum = 0, max_cost = 0;
        for(int i = 0; i < colors.size(); i++) {
            if(i > 0 && colors[i] != colors[i - 1]) {
                cost += sum - max_cost;
                sum = 0;
                max_cost = 0;
            }
            
            sum += neededTime[i];
            max_cost = max(max_cost, neededTime[i]);
        }
        
        return cost + sum - max_cost;
    }
};