class MedianFinder {
public:
    priority_queue<int> big;
    priority_queue<int, vector<int>, greater<int>> small;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((big.size() + small.size()) & 1) {
            if(num > big.top()) {
                small.push(num);
            }
            else {
                big.push(num);
                small.push(big.top());
                big.pop();
            }
        }
        else {
            if(big.size() && num > big.top()) {
                small.push(num);
                big.push(small.top());
                small.pop();
            }
            else {
                big.push(num);
            }
        }
    }
    
    double findMedian() {
        return ((big.size() + small.size()) & 1) ? big.top() : (big.top() + small.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */