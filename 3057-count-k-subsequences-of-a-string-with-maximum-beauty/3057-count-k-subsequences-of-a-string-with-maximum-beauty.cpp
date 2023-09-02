class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> cnt(26);
        
        for(auto &&c : s) {
            cnt[c - 'a']++;
        }
        
        priority_queue<pair<int, char>> heap;
        for(int i = 0; i < 26; i++) {
            if(cnt[i]) {
                heap.push({cnt[i], i + 'a'});
            }
        }
        
        long long ans = 1, last = 0, save = 1;
        while(k--) {
            if(heap.empty()) return 0;
            
            auto [time, ch] = heap.top();
            heap.pop();
            
            if(time != last) {
                ans = ans * power(last ? last : 1, save) % int(1e9 + 7);
                last = time;
                save = 1;
            }
            else {
                save++;
            }
        }
        
        int same = count(cnt.begin(), cnt.end(), last);
        if(save == same) return ans * power(last, save) % int(1e9 + 7);
        return ans * (long)pow(last, save) * nCr(same, save) % int(1e9 + 7) % int(1e9 + 7);
    }
    
    long long power(int x, int n) {
        if( n == 0) return 1;
        
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= int(1e9 + 7);
        
        if(n % 2 != 0) {
            ans *= x;
            ans %= int(1e9 + 7);
        }
        
        return ans;
    }
    
    long long fact(int n) {
        long long ans = 1;
        
        for(int i = 1; i <= n; i++) {
            ans *= i;
            ans %= int(1e9 + 7);
        }
        
        return ans;
    }
    
    long long nCr(int n, int r) {
        long long ans = fact(n);
        long long denominator = (fact(r) * fact(n - r)) % int(1e9 + 7);
        
        return (ans * power(denominator, int(1e9 + 7) - 2)) % int(1e9 + 7);
    }
};