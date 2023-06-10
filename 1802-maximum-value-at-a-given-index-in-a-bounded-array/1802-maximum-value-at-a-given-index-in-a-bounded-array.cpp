class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum;
        
        while(l < r) {
            int m = (l + r) / 2 + 1;
            
            if(check(n, index, maxSum, m)) l = m;
            else r = m - 1;
        }
        
        return l;
    }
    
    bool check(int n, int index, int maxSum, long target) {
        long x = index, y = n - index - 1;
        
        long sum = target;
        
        cout << sum << ' ';
        
        if(x <= target - 1) sum += ((target - 1) + (target - x)) * x / 2;
        else sum += ((target - 1) + 1) * (target - 1) / 2 + x - target + 1;
        
        cout << sum << ' ';
        
        if(y <= target - 1) sum += ((target - 1) + (target - y)) * y / 2;
        else sum += ((target - 1) + 1) * (target - 1) / 2 + y - target + 1;
        
        cout << sum << ' ';
        
        cout << (sum <= maxSum) << endl;
        
        return sum <= maxSum;
    }
};