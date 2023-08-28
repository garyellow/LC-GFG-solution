class MyStack {
public:
    queue<int> s;
    
    void push(int x) {
        s.push(x);
        for(int temp = s.size(); --temp;) {
            s.push(s.front());
            s.pop();
        }
    }
    
    int pop() {
        int temp = top();
        s.pop();
        return temp;
    }
    
    int top() {
        return s.front();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */