class SmallestInfiniteSet {
public:
    unsigned cur = 1;
    unordered_set<unsigned> bset;
    priority_queue<unsigned, vector<unsigned>, greater<unsigned>> bpq;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(bpq.size()) {
            unsigned temp = bpq.top();
            bpq.pop();
            bset.erase(temp);
            
            return temp;
        }
        else {
            return cur++;
        }
    }
    
    void addBack(int num) {
        if(num < cur && !bset.count(num)) {
            bset.insert(num);
            bpq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */