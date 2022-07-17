//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        for(int i = 1; i < R; i++)
            for(int j = 0; j < C; j++)
                M[i][j] += M[i - 1][j];
                
        for(int j = 1; j < C; j++)
            for(int i = 0; i < R; i++)
                M[i][j] += M[i][j - 1];
        
        vector<int> ans;
        for(int i = 0; i < Q; i++)
        {
            if(K > 1) ans.push_back(1 + 2 * bs(M, R, C, q_i[i], q_j[i], K));
            else ans.push_back(check(M, R, C, q_i[i], q_j[i], K, 0));
        }
        
        return ans;
    }
    
    bool check(const vector<vector<int>>& M, int R, int C, int i, int j, int K, int num)
    {
        if(num > i || num > j || num >= R - i || num >= C - j) return false;
        
        int temp = M[i + num][j + num] + (i - num - 1 >= 0 && j - num - 1 >= 0 ? M[i - num - 1][j - num - 1] : 0);
        temp -= (i - num - 1 >= 0 ? M[i - num - 1][j + num] : 0);
        temp -= (j - num - 1 >= 0 ? M[i + num][j - num - 1] : 0);
        
        return temp <= K;
    }
    
    int bs(const vector<vector<int>>& M, int R, int C, int i, int j, int K)
    {
        int mid;
        for(mid = 0;check(M, R, C, i, j, K, mid + 1); mid++);
        return mid;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends