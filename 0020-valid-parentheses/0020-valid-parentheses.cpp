class Solution {
public:
    bool isValid(string s) {
        stack<char> S;

        for (auto &&i : s) {
            switch(i) {
                case ')':
                    if (S.size() && S.top() == '(') S.pop();
                    else return false;
                    break;
                case ']':
                    if (S.size() && S.top() == '[') S.pop();
                    else return false;
                    break;
                case '}':
                    if (S.size() && S.top() == '{') S.pop();
                    else return false;
                    break;
            
                default:
                    S.push(i);
            }
        }

        return S.empty();
    }
};