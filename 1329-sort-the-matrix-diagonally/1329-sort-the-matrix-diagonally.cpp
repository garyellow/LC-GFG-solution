class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 1; i < mat.size(); i++)
        {
            vector<int*> cur;
            
            for(int step = 0; step < mat.front().size() && i + step < mat.size(); step++)
                cur.push_back(&(mat[i + step][step]));
            
            sort(cur);
        }
        
        vector<int*> cur;
            
        for(int step = 0; step < mat.front().size() && step < mat.size(); step++)
            cur.push_back(&(mat[step][step]));

        sort(cur);
        
        for(int j = 1; j < mat.front().size(); j++)
        {
            vector<int*> cur;
            
            for(int step = 0; step < mat.size() && j + step < mat.front().size(); step++)
                cur.push_back(&(mat[step][j + step]));
            
            sort(cur);
        }
        
        return mat;
    }
    
    void sort(vector<int*> arr)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
            
        for(auto &&i : arr)
            pq.push(*i);

        for(auto &&i : arr)
        {
            *i = pq.top();
            pq.pop();
        }
    }
};