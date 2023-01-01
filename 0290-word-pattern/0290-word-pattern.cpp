class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> S = decode(s);
        unordered_map<string, char> hash1;
        unordered_map<char, string> hash2;
        
        if(S.size() != pattern.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++)
            if(hash1.count(S[i]) > 0 || hash2.count(pattern[i]) > 0) {
                if(hash1[S[i]] != pattern[i] || hash2[pattern[i]] != S[i]) return false;
            }
            else {
                hash1[S[i]] = pattern[i];
                hash2[pattern[i]] = S[i];
            }
                
        return true;
    }
    
    vector<string> decode(string &ori) {
        string temp;
        vector<string> save;
        for(auto &&i : ori)
        {
            if(isspace(i))
            {
                save.push_back(temp);
                temp.clear();
            }
            else
                temp.push_back(i);
        }
        
        save.push_back(temp);
        
        return save;
    }
};