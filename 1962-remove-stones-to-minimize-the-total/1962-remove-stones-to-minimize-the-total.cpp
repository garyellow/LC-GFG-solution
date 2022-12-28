class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        while(k--) {
            double temp = heap.top();
            heap.pop();
            heap.push(ceil(temp / 2));
        }
        
        int cnt = 0;
        for(; heap.size(); heap.pop()) 
            cnt += heap.top();
        
        return cnt;
    }
};