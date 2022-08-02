class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<vector<bool>> gone(matrix.size(), vector<bool>(matrix.front().size()));
        
        auto cmp = [&matrix](pair<int,int> &l, pair<int,int>&r) {return matrix[l.first][l.second] > matrix[r.first][r.second];};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        gone[0][0] = true;
        
        while(--k)
        {
            auto temp = pq.top();
            pq.pop();
            
            if(temp.first + 1 < matrix.size() && !gone[temp.first + 1][temp.second]) 
            {
                pq.push({temp.first + 1, temp.second});
                gone[temp.first + 1][temp.second] = true;
            }
            
            if(temp.second + 1 < matrix.front().size() && !gone[temp.first][temp.second + 1])
            {
                pq.push({temp.first, temp.second + 1});
                gone[temp.first][temp.second + 1] = true;
            }
        }
                                                                       
        return matrix[pq.top().first][pq.top().second];
    }
};