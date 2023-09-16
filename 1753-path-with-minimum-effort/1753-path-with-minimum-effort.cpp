class Solution
{
public:
    vector<int> u;
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> heap;
        vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const int len = heights.front().size();
        
        for (int i = 0; i < heights.size(); i++)
            for (int j = 0; j < heights.front().size(); j++)
                for(auto &&dir : dirs)
                    if (checkboard(i, j, dir.first, dir.second, heights.size(), heights.front().size()))
                        heap.push({abs(heights[i][j] - heights[i + dir.first][j + dir.second]), 
                                   encode(i, j, len), encode(i + dir.first, j + dir.second, len)});

        u.resize(heights.size() * heights.front().size());
        iota(u.begin(), u.end(), 0);
        
        int ans = 0;
        for(; find(u.front()) != find(u.back()); heap.pop())
        {
            const auto temp = heap.top();
            u[find(temp[1])] = find(temp[2]);
            ans = temp[0];
        }
        
        return ans;
    }
    
    inline bool checkboard(const int &x, const int &y, const int &dx, const int &dy, const int &X, const int &Y)
    {
        return x + dx >= 0 && y + dy >= 0 && x + dx < X && y + dy < Y;
    }

    inline int encode(const int &x, const int &y, const int &len)
    {
        return x * len + y;
    }

    int find(int val)
    {
        return u[val] == val ? u[val] : u[val] = find(u[val]);
    }
};
