class Solution {
public:
    map<vector<int>, vector<int>> u;
        
    int removeStones(vector<vector<int>>& stones) {
        for(auto &&stone : stones) 
            u[stone] = stone;
        
        for(auto &&stone1 : stones) 
            for(auto &&stone2 : stones) 
                if(stone1.front() == stone2.front() || stone1.back() == stone2.back())
                    u[find(stone1)] = find(stone2);
        
        set<vector<int>> ans;
        for(auto &&[x, y] : u) 
            ans.insert(find(y));
        
        return stones.size() - ans.size();
    }
    
    vector<int> find(vector<int> &val) {
        return u[val] == val ? val : u[val] = find(u[val]);
    }
};