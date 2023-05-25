class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < nums1.size(); i++) 
            arr.push_back({nums2[i], nums1[i]});
        
        sort(arr.rbegin(), arr.rend());
        
        long long sum = 0, ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> heap;
        for(auto &&[x, y] : arr) {
            if(heap.size() == k) {
                sum -= heap.top();
                heap.pop();
            }
            
            if(heap.size() < k) {
                sum += y;
                heap.push(y);
            }
            
            
            if(heap.size() == k) {
                ans = max(ans, sum * x);
            }
        }
        
        return ans;
    }
};