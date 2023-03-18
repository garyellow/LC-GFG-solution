class DoubleListNode {
public:
    string val;
    DoubleListNode *next = nullptr;
    DoubleListNode *prep;
    
    DoubleListNode(string &val, DoubleListNode *link) : val(val), prep(link) {};
};

class BrowserHistory {
public:
    DoubleListNode *cur;
    BrowserHistory(string homepage) : cur(new DoubleListNode(homepage, nullptr)) {

    }
    
    void visit(string url) {
        cur->next = new DoubleListNode(url, cur);
        cur = cur->next;
    }
    
    string back(int steps) {
        while(steps-- && cur->prep != nullptr) 
            cur = cur->prep;
        
        return cur->val;
    }
    
    string forward(int steps) {
        while(steps-- && cur->next != nullptr) 
            cur = cur->next;
        
        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */