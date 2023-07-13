class Solution {
public:
    vector<vector<bool>> graph;     // adjacency matrix
    vector<int> visit;              // 記錄DFS遍歷過的點
    int all;
    bool cycle = false;             // 記錄DFS的過程中是否偵測到環
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<bool>>(numCourses, vector<bool>(numCourses));
        visit = vector<int>(numCourses);
        
        for(auto i : prerequisites)
            graph[i[1]][i[0]] = true;
        
        all = numCourses;
    
        for (int i = 0; i < numCourses; i++)
            if (!visit[i]) DFS(i);
    
        return !cycle;
    }
    
    void DFS(int now)
    {
        // back edge，有環。
        if (visit[now] == 1) {cycle = true; return;}
        
        // forward edge、cross edge。
        if (visit[now] == 2) return;

        visit[now] = 1;
        
        for (int t = 0; t < all; t++)
            if (graph[now][t]) DFS(t);
        
        visit[now] = 2;
    }
};