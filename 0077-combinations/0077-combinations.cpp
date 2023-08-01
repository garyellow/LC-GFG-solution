class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        bt(1, temp, ans, n, k);
        
        return ans;
    }
    
    void bt(int cur, vector<int> &temp, vector<vector<int>> &ans, int n, int k) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = cur; i <= n; i++) {
            temp.push_back(i);
            bt(i + 1, temp, ans, n, k);
            temp.pop_back();
        }
    }
};