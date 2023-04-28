class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, string> u;
        for(auto &&str : strs)
            u[str] = str;
        
        for(int i = 0; i < strs.size(); i++) {
            for(int j = i + 1; j < strs.size(); j++) {
                int cnt = 0;
                for(int k = 0; k < strs.front().size(); k++)
                    cnt += (strs[i][k] != strs[j][k]);
                
                if(cnt == 0 || cnt == 2)
                    u[find(strs[i], u)] = find(strs[j], u);
            }
        }
        
        unordered_set<string> s;
        for(auto &&[x, y] : u)
            s.insert(find(y, u));
        
        return s.size();
    }
    
    string find(string val, unordered_map<string, string>& u) {
        return u[val] == val ? val : u[val] = find(u[val], u);
    }
};