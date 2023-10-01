class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        
        string ans;
        for(auto &&ch : s) {
            if(ch == ' ') {
                while(st.size()) {
                    ans.push_back(st.top());
                    st.pop();
                }
                
                ans.push_back(ch);
            }
            else st.push(ch);
        }
        
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};