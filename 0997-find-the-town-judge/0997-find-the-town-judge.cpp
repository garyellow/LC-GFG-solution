class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> check(n + 1);

        for(auto &&i : trust) 
            check[i[0]]--, check[i[1]]++;
        
        for(int i = 1; i < check.size(); i++) 
            if(check[i] == n - 1) return i;

        return -1;
    }
};