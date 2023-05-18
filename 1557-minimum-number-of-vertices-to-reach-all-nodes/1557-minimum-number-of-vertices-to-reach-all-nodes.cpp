class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> isEnd(n, true);
        
        for(auto &&edge : edges)
            isEnd[edge[1]] = false;
        
        vector<int> ans;
        for(int i = 0; i < isEnd.size(); i++) 
            if(isEnd[i]) ans.push_back(i);
        
        return ans;
    }
};