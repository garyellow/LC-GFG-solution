class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> plant;        
        
        for(int i = 0; i < plantTime.size(); i++)
            plant.push_back({growTime[i], plantTime[i]});
        
        sort(plant.rbegin(), plant.rend());
        
        int day = 0;
        int ans = 0;
        for(auto &&[grow_t, plant_t] : plant)
            ans = max(ans, grow_t + (day += plant_t));
        
        return ans;
    }
};