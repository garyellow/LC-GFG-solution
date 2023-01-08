class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // sort(points.begin(), points.end());
        
        int ans = 1;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<double, int> record;
            
            for(int j = 0; j < points.size(); j++) {
                double m;
                if(i == j) continue;
                else if(i > j) m = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                else m = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                
                record[m]++;
            }
            
            if(record.size())
                ans = max(ans, max_element(record.begin(), record.end(), [](auto &&x, auto &&y){return x.second < y.second;})->second + 1);
        }
        
        return ans;
    }
};