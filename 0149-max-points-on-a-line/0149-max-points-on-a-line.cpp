class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int cnt = 0;
                double m = (double)(points[i][0] - points[j][0]) / (points[i][1] - points[j][1]);
                
                for(int k = 0; k < points.size(); k++) 
                    if(i == k || (double)(points[i][0] - points[k][0]) / (points[i][1] - points[k][1]) == m)
                        cnt++;
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};