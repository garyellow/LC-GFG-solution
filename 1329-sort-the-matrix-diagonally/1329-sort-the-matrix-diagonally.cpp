class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int*>> temp;
        
        for(int i = 1; i < mat.size(); i++)
        {
            vector<int*> cur;
            
            for(int step = 0; step < mat.front().size() && i + step < mat.size(); step++)
                cur.push_back(&(mat[i + step][step]));
            
            temp.push_back(cur);
        }
        
        vector<int*> cur;
            
        for(int step = 0; step < mat.front().size() && step < mat.size(); step++)
            cur.push_back(&(mat[step][step]));

        temp.push_back(cur);
        
        for(int j = 1; j < mat.front().size(); j++)
        {
            vector<int*> cur;
            
            for(int step = 0; step < mat.size() && j + step < mat.front().size(); step++)
                cur.push_back(&(mat[step][j + step]));
            
            temp.push_back(cur);
        }
        
        for(auto &&line : temp)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            
            for(auto &&i : line)
                pq.push(*i);
            
            for(auto &&i : line)
            {
                *i = pq.top();
                pq.pop();
            }
        }
        
        return mat;
    }
};