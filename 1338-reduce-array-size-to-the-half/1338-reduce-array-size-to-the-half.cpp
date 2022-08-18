class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        
        for(auto &&i : arr)
            cnt[i]++;
        
        priority_queue<int> heap;
        
        for(auto &&i : cnt)
            heap.push(i.second);
        
        int half = arr.size() / 2;
        
        int ans;
        for(ans = 0; half > 0; ans++)
        {
            half -= heap.top();
            heap.pop();
        }
        
        return ans;
    }
};