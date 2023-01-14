class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> u(26);
        
        for(int i = 0; i < 26; i++) 
            u[i] = i;
        
        for(int i = 0; i < s1.size(); i++) {
            if(find(s1[i] - 'a', u) > find(s2[i] - 'a', u)) u[find(s1[i] - 'a', u)] = find(u[s2[i] - 'a'], u);
            else u[find(s2[i] - 'a', u)] = find(u[s1[i] - 'a'], u);
        }
        
        for(auto &&c : baseStr) {
            c = find(c - 'a', u) + 'a';
        }
        
        return baseStr;
    }
    
    int find(int val, vector<int>& u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};