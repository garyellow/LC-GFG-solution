class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();
        
        for(int i = 0; i <= n / 2 - !(n & 1); i++)
        {
            for(int j = 0; j <= m / 2 - 1; j++)
            {
                int &a = matrix[i][j];
                int &b = matrix[j][n - i - 1];
                int &c = matrix[n - i - 1][m - j - 1];
                int &d = matrix[m - j - 1][i];
                
                int temp = d;
                d = c;
                c = b;
                b = a;
                a = temp;
            }
        }
    }
};