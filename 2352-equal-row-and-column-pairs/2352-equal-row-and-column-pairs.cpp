class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // hash<size_t> h;
        map<vector<int>, int> table;
        
        for(int i = 0; i < grid.size(); i++) {
            size_t temp = 0;
            
            // for(int j = 0; j < grid.size(); j++) {
            //     temp = h(temp + grid[i][j] * i);
            // }
            // cout << i << ' ' << temp << endl; 
            table[grid[i]]++;
        }
        
        int cnt = 0;
        
        for(int j = 0; j < grid.size(); j++) {
            // size_t temp = 0;
            vector<int> temp;
            
            for(int i = 0; i < grid.size(); i++) {
                // temp = h(temp + grid[i][j] * j);
                temp.push_back(grid[i][j]);
            }
            
            // cout << j << ' ' << temp << endl; 
            cnt += table[temp];
        }
        
        return cnt;
    }
};