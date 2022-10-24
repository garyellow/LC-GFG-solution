class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        for(int i = 0; i < arr.size(); i++)
            bt(set<char>(), i, arr);
        
        return ans;
    }
    
    void bt(set<char> last, int cnt, vector<string>& arr) {
        for(auto &&ch : arr[cnt]) {
            if(last.find(ch) != last.end()) return;
            last.insert(ch);
        }
        
        ans = max(ans, int(last.size()));
            
        for(int i = cnt + 1; i < arr.size(); i++)
            bt(last, i, arr);
    }
};