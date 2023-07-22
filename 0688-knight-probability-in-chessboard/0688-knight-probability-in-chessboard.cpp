class Solution {
public:
    vector<vector<vector<double>>> dp;
    static vector<pair<int, int>> next;
    double knightProbability(int n, int k, int row, int column) {
        if(dp.empty()) {
            dp = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        }
        
        if(row < 0 || column < 0 || row >= n || column >= n) return 0;
        if(k == 0) return row >= 0 && column >= 0 && row < n && column < n;
        
        if(dp[row][column][k] == -1) {
            dp[row][column][k] = 0;
            
            for(auto &&[dx, dy]: next) {
                dp[row][column][k] += 1.0 / 8 * knightProbability(n, k - 1, row + dx, column + dy);
            }
        }
        
        return dp[row][column][k];
    }
};

vector<pair<int, int>> Solution::next = vector<pair<int, int>>({{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}});