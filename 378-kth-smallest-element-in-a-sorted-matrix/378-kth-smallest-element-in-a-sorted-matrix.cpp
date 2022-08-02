class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({matrix[0][0], {0, 0}});
        
        for(;--k ;)
        {
            auto temp = pq.top();
            pq.pop();
            
            if(temp.second.first + 1 < matrix.size()) 
            {
                pq.push({matrix[temp.second.first + 1][temp.second.second], {temp.second.first + 1, temp.second.second}});
                matrix[temp.second.first + 1][temp.second.second] = INT_MAX;
            }
            if(temp.second.second + 1 < matrix.front().size())
            {
                pq.push({matrix[temp.second.first][temp.second.second + 1], {temp.second.first, temp.second.second + 1}});
                matrix[temp.second.first][temp.second.second + 1] = INT_MAX;
            }
        }
                                                                       
        return pq.top().first;
    }
};