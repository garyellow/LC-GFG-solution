class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        vector<int> ans;
        for(int index = 0; index < tasks.size(); ) {
            while(index < tasks.size() && time >= tasks[index].front()) {
                heap.push({tasks[index][1], tasks[index][2]});
                index++;
            }
            
            if(heap.size()) {
                auto &&[pt, id] = heap.top();
                
                time += pt;
                ans.push_back(id);
                
                heap.pop();
            }
            else 
                time = tasks[index].front();
        }
        
        for(; heap.size(); heap.pop())
            ans.push_back(heap.top().second);
        
        return ans;
    }
};