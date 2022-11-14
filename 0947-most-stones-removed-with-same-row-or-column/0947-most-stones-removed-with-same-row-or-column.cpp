class Solution {
public:
    unordered_map<int, int> u;
    int removeStones(vector<vector<int>>& stones) {
        for(auto &&stone : stones) 
            u[stone.front() * 1e4 + stone.back()] = stone.front() * 1e4 + stone.back();
        
        for(auto &&stone1 : stones) 
            for(auto &&stone2 : stones) 
                if(stone1.front() == stone2.front() || stone1.back() == stone2.back())
                    u[find(stone1.front() * 1e4 + stone1.back())] = find(stone2.front() * 1e4 + stone2.back());
        
        unordered_set<int> ans;
        for(auto &&[x, y] : u) 
            ans.insert(find(y));
        
        return stones.size() - ans.size();
    }
    
    int find(const int &val) {
        return u[val] == val ? val : u[val] = find(u[val]);
    }
};