class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int, int> s;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.count(val)) return false;
        
        a.push_back(val);
        s[val] = a.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val) == false) return false;
        
        int last = a.back();
        s[last] = s[val];
        a[s[last]] = a.back();
        a.pop_back();
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */