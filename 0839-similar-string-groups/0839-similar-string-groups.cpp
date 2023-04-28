class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int, int> u;
        for(int i = 0; i < strs.size(); i++)
            u[i] = i;
        
        for(int i = 0; i < strs.size(); i++) {
            for(int j = i + 1; j < strs.size(); j++) {
                int cnt = 0;
                for(int k = 0; k < strs.front().size() && cnt <= 2; k++)
                    cnt += (strs[i][k] != strs[j][k]);
                
                if(cnt == 0 || cnt == 2)
                    u[find(i, u)] = find(j, u);
            }
        }
        
        unordered_set<int> s;
        for(auto &&[x, y] : u)
            s.insert(find(y, u));
        
        return s.size();
    }
    
    int find(int val, unordered_map<int, int>& u) {
        return u[val] == val ? val : u[val] = find(u[val], u);
    }
};