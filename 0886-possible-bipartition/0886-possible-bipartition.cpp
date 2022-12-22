class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, -1);
        vector<vector<int>> adj(n + 1);
        for(auto &&dislike : dislikes) {
            adj[dislike.front()].push_back(dislike.back());
            adj[dislike.back()].push_back(dislike.front());
        }

	    for(int s = 1; s <= n; s++) {
            if(color[s] == -1) {
                color[s] = 1;
                queue<int> bfs;
                bfs.push(s);
                while(bfs.size()) {
                    int u = bfs.front();
                    bfs.pop();
                    for(auto &&v : adj[u]) {
                        if(color[v] == -1) {
                            color[v] = color[u] ^ 1;
                            bfs.push(v);
                        }
                        else 
                            if(color[u] == color[v])
                                return false;
                    }
                }
            }
        }
        
	    return true;
    }
};