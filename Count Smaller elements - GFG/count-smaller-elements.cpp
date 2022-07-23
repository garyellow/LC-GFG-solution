//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *a, int n) {
	    vector<pair<int, int>> arr;
        vector<int> cnt(n);
        
        for(int i = 0; i < n; i++)
            arr.push_back({a[i], i});
        
        mergeSort(0, arr.size() - 1, arr, cnt);
        
        return cnt;
        
    }
    
    vector<pair<int, int>> mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int> &cnt)
    {
        if(left < right)
        {
            int mid = left + (right - left) / 2;

            auto a = mergeSort(left, mid, arr, cnt);
            auto b = mergeSort(mid + 1, right, arr, cnt);

            int num = mid + 1;
            merge(a.begin(), a.end(), b.begin(), b.end(), arr.begin() + left, [&cnt,&num,right](auto &l, auto &r){
                if(l.first >= r.first)
                {
                    num++;
                    return true;
                }
                else
                {
                    cnt[r.second] += right - num + 1;
                    return false;
                }
            });
        }
        return {arr.begin() + left, arr.begin() + right + 1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends