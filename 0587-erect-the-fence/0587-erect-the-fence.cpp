class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        
        deque<vector<int>> F;
        
        for (auto && T : trees)
        {
            while (F.size() >= 2 and cross(T,F[F.size() - 2], F[F.size() - 1]) < 0)
                F.pop_back();
            F.push_back(T);

            while (F.size() >= 2 and cross(T, F[1], F[0]) > 0)
                F.pop_front();
            F.push_front(T);
        }
        
        set<vector<int>> uni(F.begin(), F.end());
        return vector<vector<int>>(uni.begin(), uni.end());
    }
    
    int cross(const vector<int> &T, const vector<int> &A, const vector<int> &B)
    {
        return (T[1] - B[1]) * (B[0] - A[0]) - (B[1] - A[1]) * (T[0]-B[0]);
    }
};