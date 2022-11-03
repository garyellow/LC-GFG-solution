class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> record;
        
        int cnt = 0;
        for(auto &&word : words) {
            string r({word.rbegin(), word.rend()});
            
            if(record[r]) {
                cnt += 4;
                record[r]--;
            }
            else
                record[word]++;
        }
        
        for(auto &&[word, times] : record) {
            if(times && word.front() == word.back()) {
                cnt += 2;
                break;
            }
        }
        
        return cnt;
    }
};