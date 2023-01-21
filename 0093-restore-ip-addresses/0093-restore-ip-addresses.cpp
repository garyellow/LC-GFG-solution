class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string& s) {
        vector<string> temp;
        backtracking(0, temp, s);
        
        return ans;
    }
    
    void backtracking(int&& index, vector<string>& cur, string& s) {
        if(cur.size() > 4) return;
        if(cur.size() == 4 && index == s.size()) {
            auto &&temp = accumulate(cur.begin(), cur.end(), string());
            temp.pop_back();
            ans.push_back(temp);
        }
        
        for(int i = index; i < min(index + 4, int(s.size())); i++) {
            auto &&temp = s.substr(index, i - index + 1);
            if(stoi(temp) > 255 || temp[0] == '0' && temp.size() != 1) continue;
            
            cur.push_back(temp + ".");
            backtracking(i + 1, cur, s);
            cur.pop_back();
        }
    }
};