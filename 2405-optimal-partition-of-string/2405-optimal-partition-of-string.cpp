class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        unordered_set<char> sub;
        
        for(auto &&c : s) {
            if(sub.count(c)) {
                cnt++;
                sub.clear();
            }
            
            sub.insert(c);
        }
        
        return cnt + 1;
    }
};