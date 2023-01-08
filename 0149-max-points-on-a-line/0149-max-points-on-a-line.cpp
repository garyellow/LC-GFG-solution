class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<double, int> record;
            
            for(int j = 0; j < points.size(); j++) {
                double m = 0;
                if(i == j) record[m];
                else {
                    m = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    record[m]++;
                }
            }
            
            ans = max(ans, max_element(record.begin(), record.end(), [](auto &&x, auto &&y){return x.second < y.second;})->second + 1);
        }
        
        return ans;
    }
};