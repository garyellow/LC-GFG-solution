// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

#include <bitset>
class Solution {
  public:
    int minVal(int a, int b) {
        bitset<32> A(a), B(b), C(a);
        int ori = A.count(), need = B.count();
        
        if(ori == need)
            return a;
        else if(ori > need)
        {
            need = ori - need;
            for(int i = 0; need && i < A.size(); i++)
            {
                if(A[i])
                {
                    C.set(i, 0);
                    need--;
                }
            }
        }
        else
        {
            need = need - ori;
            for(int i = 0; need && i < A.size(); i++)
            {
                if(A[i] == 0)
                {
                    C.set(i);
                    need--;
                }
            }
        }
        
        return C.to_ulong();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends