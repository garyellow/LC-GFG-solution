class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        
        char last = 0;
        int sum = 0, max_cost = 0;
        for(int i = 0; i < colors.size(); i++) {
            if(colors[i] == last)
            {
                sum += neededTime[i];
                max_cost = max(max_cost, neededTime[i]);
            }
            else
            {
                cost += sum - max_cost;
                sum = neededTime[i];
                max_cost = neededTime[i];
                
                last = colors[i];
            }
        }
        
        return cost + sum - max_cost;
    }
};