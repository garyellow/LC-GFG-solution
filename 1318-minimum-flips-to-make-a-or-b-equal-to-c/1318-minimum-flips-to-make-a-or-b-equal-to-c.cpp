class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        
        for(int i = 1; i <= 1e9; i <<= 1) {
            bool x = a & i, y = b & i, z = c & i;
            
            if(z) {
                if(!x && !y) cnt++;
            }
            else {
                if(x) cnt++;
                if(y) cnt++;
            }
        }
        
        return cnt;
    }
};