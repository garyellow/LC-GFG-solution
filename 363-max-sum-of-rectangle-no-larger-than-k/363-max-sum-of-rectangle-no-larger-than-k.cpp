class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int maxSum = INT_MIN;
        
        for(int begin_i = 0; begin_i < matrix.front().size(); begin_i++)
        {
            vector<int> sumArr(matrix.size(), 0);
            for(int end_i = begin_i; end_i < matrix.front().size(); end_i++)
            {
                for(int begin_j = 0; begin_j < matrix.size(); begin_j++) sumArr[begin_j] += matrix[begin_j][end_i];
                for(int begin_j = 0; begin_j < matrix.size(); begin_j++)
                {
                    int sum = 0;
                    for(int end_j = begin_j; end_j < matrix.size(); end_j++)
                    {
                        sum += sumArr[end_j];
                        if(sum > maxSum && sum <= k) maxSum = sum;
                    }
                }
            }
        }
        
        return maxSum;
    }
};