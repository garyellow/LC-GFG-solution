class MyCircularQueue {
public:
    ListNode* first = nullptr;
    ListNode* last = nullptr;
    int cnt = 0;
    int max_cnt;
    
    MyCircularQueue(int k) {
        max_cnt = k;
    }
    
    bool enQueue(int value) {
        if(cnt < max_cnt)
        {
            if(cnt == 0) first = last = new ListNode(value);
            else last = last->next = new ListNode(value);
            
            cnt++;
            return true;
        }
        
        return false;
    }
    
    bool deQueue() {
        if(cnt > 0)
        {
            first = first->next;
            
            cnt--;
            return true;
        }
        
        return false;
    }
    
    int Front() {
        return cnt ? first->val : -1;
    }
    
    int Rear() {
        return cnt ? last->val : -1;
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == max_cnt;
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