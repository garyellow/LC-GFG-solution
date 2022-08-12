//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string &str, int n)
    {
        string u, d;
        
        for(auto &&c : str)
            if(isupper(c)) u.push_back(c);
            else d.push_back(c);
            
        sort(u.begin(), u.end(), greater<char>());
        sort(d.begin(), d.end(), greater<char>());
        
        for(auto &&c : str)
            if(isupper(c)) 
            {
                c = u.back();
                u.pop_back();
            }
            else
            {
                c = d.back();
                d.pop_back();
            }
            
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends