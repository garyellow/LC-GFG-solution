class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 1, r = 2000;
        
        while(l < r) {
            int mid = (l + r) / 2;
            
            if(find(arr, mid) < k) l = mid + 1;
            else r = mid;
        }
        
        return l;
    }
    
    int find(vector<int>& arr, int num) {
        return num - (upper_bound(arr.begin(), arr.end(), num) - arr.begin());
    }
};