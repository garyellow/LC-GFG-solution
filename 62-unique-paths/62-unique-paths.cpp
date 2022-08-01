class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        
        long ans = 1;
        
        int i = max(m, n) + 1, j = min(m, n);
        
        while(i <= m + n || j > 0)
        {
            if(j > 0 && ans % j == 0)
                ans /= j--;
            else
                ans *= i++;
        }
        
        return ans;
    }
};