class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        for(auto &&building : buildings) {
            swap(building[2], building[1]);
            swap(building[1], building[0]);
        }
        
        priority_queue<vector<int>> heap;
        
        int cur = 0, index = 0;
        vector<vector<int>> ans;
        while(heap.size() || index < buildings.size()) {
            if(heap.empty())
            {
                int begin = buildings[index][1];
                while(index < buildings.size() && buildings[index][1] == begin) heap.push(buildings[index++]);
                
                ans.push_back({heap.top()[1], heap.top()[0]});
                cur = heap.top()[0];
            }
            else
            {
                if(index < buildings.size() && buildings[index][1] <= heap.top()[2])
                {
                    int begin = buildings[index][1];
                    while(index < buildings.size() && buildings[index][1] == begin) heap.push(buildings[index++]);
                    
                    if(cur < heap.top()[0])
                    {
                        ans.push_back({heap.top()[1], heap.top()[0]});
                        cur = heap.top()[0];
                    }
                }
                else
                {
                    int temp = heap.top()[2];
                    while(heap.size() && heap.top()[2] <= temp) heap.pop();
                    
                    if(heap.empty())
                    {
                        ans.push_back({temp, 0});
                        cur = 0;
                    }
                    else if(cur > heap.top()[0])
                    {
                        ans.push_back({temp, heap.top()[0]});
                        cur = heap.top()[0];
                    }
                }
            }
        }
        
        return ans;
    }
};