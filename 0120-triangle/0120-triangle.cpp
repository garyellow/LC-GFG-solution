class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int h = triangle.size() - 2; h >= 0; h--)
            for(int i = 0; i < triangle[h].size(); i++)
                triangle[h][i] += min(triangle[h + 1][i + 1], triangle[h + 1][i]);
        
        return triangle.front().front();
    }
};