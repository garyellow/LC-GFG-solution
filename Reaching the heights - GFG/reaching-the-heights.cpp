// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    deque<int> floors;
    for(int i = 0; i < n; i++)
        floors.push_back(a[i]);
        
    sort(floors.begin(), floors.end());
    
    vector<int> ans;
    bool odd = true;
    while(floors.size())
    {
        if(odd)
        {
            ans.push_back(floors.back());
            floors.pop_back();
        }
        else
        {
            ans.push_back(floors.front());
            floors.pop_front();
        }
        
        odd = !odd;
    }
    
    int cur = 1;
    odd = true;
    for(auto &&f : ans)
    {
        cur += (odd ? f : -f);
        odd = !odd;
        
        if(cur <= 1) return {-1};
    }
    
    return ans;
}
