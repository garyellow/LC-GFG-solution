class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 0; j < matrix.front().size(); j++)
                matrix[i][j] += matrix[i - 1][j];
                
        for(int j = 1; j < matrix.front().size(); j++)
            for(int i = 0; i < matrix.size() ; i++)
                matrix[i][j] += matrix[i][j - 1];
        
        int cnt = 0;
        
        for(int is = 0; is < matrix.size(); is++)
        {
            for(int ie = is; ie < matrix.size(); ie++)
            {
                for(int js = 0; js < matrix.front().size(); js++)
                {
                    for(int je = js; je < matrix.front().size(); je++)
                    {
                        if(check(matrix, is, ie, js, je) == target)
                            cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
    
    int check(const vector<vector<int>>& matrix, int is, int ie, int js, int je)
    {
        int temp = matrix[ie][je] + (is - 1 >= 0 && js - 1 >= 0 ? matrix[is - 1][js - 1] : 0);
        temp -= (is - 1 >= 0 ? matrix[is - 1][je] : 0);
        temp -= (js - 1 >= 0 ? matrix[ie][js - 1] : 0);
        
        return temp;
    }
};