class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = 0;
        vector<int> u(vals.size());
        vector<vector<int>> graph(vals.size());
        
		for(int i = 0; i < vals.size(); i++) {
			u[i] = i;
			graph[i] = {vals[i], 1};
		}
        
        sort(edges.begin(), edges.end(), [&vals](vector<int>& x,vector<int>& y){
	    	return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
		});
        
		for(int i = 0; i < edges.size(); i++){
			int a = find(edges[i][0], u);
			int b = find(edges[i][1], u);
			if(graph[a][0] != graph[b][0]){
				if(graph[a][0] > graph[b][0]) u[b] = a;
				else u[a] = b;
			}
			else {
				u[a] = b;
				ans += graph[a][1] * graph[b][1];
				graph[b][1] += graph[a][1];
			}
		}
		return ans + vals.size();
	}
    
    int find(int val, vector<int>& u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};