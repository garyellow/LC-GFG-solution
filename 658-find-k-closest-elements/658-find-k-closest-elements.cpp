class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        for(auto &&i : arr)
            heap.push({abs(i - x), i});
        
        list<int> temp;
        while(k--) {
            if(heap.top().second <= temp.front()) temp.push_front(heap.top().second);
            else temp.push_back(heap.top().second);
            
            heap.pop();
        }
        
        return vector<int>(temp.begin(), temp.end());
    }
};