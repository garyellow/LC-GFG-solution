class Solution {
public:
    int maximum69Number (int num) {
        for(int i = 1000; i; i /= 10) {
            if(num % (i * 10) / i == 6) {
                num += 3 * i;
                break;
            }
        }
        
        return num;
    }
};