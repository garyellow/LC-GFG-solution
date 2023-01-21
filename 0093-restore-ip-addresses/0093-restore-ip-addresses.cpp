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
            for(auto &&str : cur)
                if(stoi(str) > 255 || str[0] == '0' && str.size() != 2)
                    return;
            
            auto &&temp = accumulate(cur.begin(), cur.end(), string());
            temp.pop_back();
            ans.push_back(temp);
        }
        
        for(int i = index; i < min(index + 4, int(s.size())); i++) {
            cur.push_back(s.substr(index, i - index + 1) + ".");
            backtracking(i + 1, cur, s);
            cur.pop_back();
        }
    }
};