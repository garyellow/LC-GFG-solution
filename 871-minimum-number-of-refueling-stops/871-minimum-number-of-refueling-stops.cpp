class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> fuel;
        
        reverse(stations.begin(), stations.end());
        
        fuel.push(startFuel);
        startFuel = 0;

        int cnt;
        for(cnt = -1; fuel.size() && startFuel < target; cnt++)
        {
            startFuel += fuel.top();
            fuel.pop();
            
            while(stations.size() && stations.back().front() <= startFuel)
            {
                fuel.push(stations.back().back());
                stations.pop_back();
            }
        }
        
        return startFuel >= target ? cnt : -1;
    }
};