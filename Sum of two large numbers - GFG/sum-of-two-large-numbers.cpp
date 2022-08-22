//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        bool carry = false;
        X = check(X);
        Y = check(Y);
        
        string ans;
        while(X.size() && Y.size())
        {
            int temp = carry + X.back() + Y.back() - 2 * '0';
            X.pop_back();
            Y.pop_back();
            
            carry = temp > 9;
            ans.push_back(temp % 10 + '0');
        }
        
        while(X.size())
        {
            int temp = carry + X.back() - '0';
            X.pop_back();
            
            carry = temp > 9;
            ans.push_back(temp % 10 + '0');
        }
        
        while(Y.size())
        {
            int temp = carry + Y.back() - '0';
            Y.pop_back();
            
            carry = temp > 9;
            ans.push_back(temp % 10 + '0');
        }
        
        if(carry) ans.push_back('1');
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    string check(const string &s)
    {
        string new_s;
        bool record = false;
        
        for(auto &&c : s)
        {
            if(c != '0')
                record = true;
            
            if(record)
                new_s.push_back(c);
        }
        
        return new_s.size() ? new_s : "0";
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends