class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) sort(s.begin(), s.end());
        else {
            auto str = s;
            for (int i = 0; i < str.size(); i++)
                s = min(s, str.substr(i) + str.substr(0,i));
        }
        
        return s;
    }
}; 