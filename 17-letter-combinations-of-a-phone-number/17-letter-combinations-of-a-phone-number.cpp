class Solution {
public:
    unordered_map<char, string> record;
    vector<string> ans;
    string temp;
    
    vector<string> letterCombinations(string digits) {
        record['2'] = "abc";
        record['3'] = "def";
        record['4'] = "ghi";
        record['5'] = "jkl";
        record['6'] = "mno";
        record['7'] = "pqrs";
        record['8'] = "tuv";
        record['9'] = "wxyz";
        
        if(!digits.empty())
            bt(digits);
        
        return ans;
    }
    
    void bt(string val)
    {
        if(val.empty())
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto &&i : record[val.front()])
        {
            temp.push_back(i);
            bt(val.substr(1));
            temp.pop_back();
        }
    }
};