class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> all;

        for (const auto& i : grid)
            for (auto j : i)
                all.push_back(j);

        if (all.size() > 1)
            rotate(all.begin(), all.begin() + all.size() - k % all.size(),
                   all.end());

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.front().size(); j++)
                grid[i][j] = all[i * grid.front().size() + j];

        return grid;
    }
};