class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        
        while(heap.size() > 1)
        {
            int max1 = heap.top(); heap.pop();
            int max2 = heap.top(); heap.pop();
            
            heap.push(max1 - max2);
        }
        
        return heap.top();
    }
};