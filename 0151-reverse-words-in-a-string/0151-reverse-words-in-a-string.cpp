class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> st;
        
        while(ss >> s)st.push_back(s + ' ');
        
        s = accumulate(st.rbegin(), st.rend(), string());
        s.pop_back();
        
        return s;
    }
};