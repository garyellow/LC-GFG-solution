class MyCircularQueue {
public:
    list<int> q;
    int max_cnt;
    
    MyCircularQueue(int k) {
        max_cnt = k;
    }
    
    bool enQueue(int value) {
        if(q.size() < max_cnt)
        {
            q.push_back(value);
            return true;
        }
        
        return false;
    }
    
    bool deQueue() {
        if(q.size() > 0)
        {
            q.pop_front();
            return true;
        }
        
        return false;
    }
    
    int Front() {
        return q.size() ? q.front() : -1;
    }
    
    int Rear() {
        return q.size() ? q.back() : -1;
    }
    
    bool isEmpty() {
        return q.size() == 0;
    }
    
    bool isFull() {
        return q.size() == max_cnt;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */