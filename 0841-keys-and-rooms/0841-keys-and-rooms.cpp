class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> check(rooms.size(), true);
        check[0] = false;
        
        stack<int> bfs({0});
        while(bfs.size()) {
            int temp = bfs.top();
            bfs.pop();
            
            for(auto &&net : rooms[temp]) {
                if(check[net]) {
                    bfs.push(net);
                    check[net] = false;
                }
            }
        }
        
        return !accumulate(check.begin(), check.end(), 0);
    }
};