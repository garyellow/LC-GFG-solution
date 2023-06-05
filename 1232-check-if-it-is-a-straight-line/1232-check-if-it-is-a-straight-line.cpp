class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        
        double m = 1.0 * (coordinates[0][0] - coordinates[1][0]) / (coordinates[0][1] - coordinates[1][1]);
        
        for(int i = 2; i < coordinates.size() ; i++) {
            if(1.0 * (coordinates[0][0] - coordinates[i][0]) / (coordinates[0][1] - coordinates[i][1]) != m) {
                return false;
            }
        }
        
        return true;
    }
};