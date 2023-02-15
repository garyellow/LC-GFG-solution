class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        bool carry = false;
        
        while(num.size() || k)
        {
            int temp = carry;
            if(num.size()) temp += num.back(), num.pop_back();
            if(k) temp += k % 10, k /= 10;

            carry = temp >= 10;
            ans.push_back(temp % 10);
        }
        
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};