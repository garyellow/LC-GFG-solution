class Solution {
public:
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string &s) {
        vector<string> temp;
        backtracking(temp, s);
        return ans;
    }
    
    void backtracking(vector<string>&temp, const string &s) {
        if(s.size() == 0) ans.push_back(temp);
        
        for(int i = 1; i <= s.size(); i++) {
            if(isPalindrome(s.substr(0, i))) {
                temp.push_back(s.substr(0, i));
                backtracking(temp, s.substr(i, s.size() - i));
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s) {
        return s == string(s.rbegin(), s.rend());
    }
};