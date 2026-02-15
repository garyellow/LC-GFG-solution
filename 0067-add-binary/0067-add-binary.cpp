class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        bool carry = false;
        
        while(a.size() || b.size()) {
            int temp = carry;
            if(a.size()) temp += a.back() - '0', a.pop_back();
            if(b.size()) temp += b.back() - '0', b.pop_back();
            
            carry = temp / 2;
            ans.push_back(temp % 2 + '0');
        }
        
        if(carry) ans.push_back('1');
        ranges::reverse(ans);
        return ans;
    }
};