class Solution {
public:
    vector<string> ans;
    
    static vector<vector<char>> phone;
    vector<string> letterCombinations(string digits) {
        if(digits.size()) {
            string temp;
            bt(temp, 0, digits);
        }
        
        return ans;
    }
    
    void bt(string &temp, int cur, string &digits) {
        if(cur == digits.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(auto &&ch : phone[digits[cur] - '0']) {
            temp.push_back(ch);
            bt(temp, cur + 1, digits);
            temp.pop_back();
        }
    }
};

vector<vector<char>> Solution::phone = vector<vector<char>>({
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'},
});