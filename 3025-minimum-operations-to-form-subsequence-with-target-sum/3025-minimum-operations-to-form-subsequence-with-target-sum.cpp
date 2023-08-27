class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> bits(32);
        
        for(auto &&num : nums) {
            bits[log2(num)]++;
        }
        
        bitset<32> t(target);
        
        int cnt = 0;
        for(int i = 0; i < 32; i++) {
            if(t[i]) {
                bool check = false;
                for(int b = i; b < 32; b++) {
                    if(bits[b]) {
                        bits[b]--;
                        for(int cur = b - 1; cur >= i; cur--) bits[cur]++;
                        cnt += b - i;
                        check = true;
                        break;
                    }
                }
                
                if(!check) return -1;
            }
            
            if(i < 31) {
                bits[i + 1] += bits[i] / 2;
                bits[i] %= 2;
            }
        }
         
        return cnt;
    }
};