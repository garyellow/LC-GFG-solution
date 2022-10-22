class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        unordered_map<char, int> cur;
        
        for(auto &&ch : t)
            table[ch]++;
        
        int left, right;
        left = right = 0; 
        
        string ans;
        while(right <= s.size()) {
            if(check(table, cur)) {
                auto temp = s.substr(left, right - left);
                // cout << temp << endl;
                if(ans.size() == 0 || ans.size() > temp.size()) ans = temp;
                cur[s[left]]--;
                left++;
            } 
            else {
                if(right == s.size()) break;
                
                cur[s[right]]++;
                right++;
            }
        }
        
        return ans;
    }
    
    bool check(unordered_map<char, int> &table, unordered_map<char, int>&cur) {
        for(auto [ch, time] : table)
            if(cur[ch] < time) return false;
        
        return true;
    }
};