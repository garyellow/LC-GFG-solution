class LFUCache {
public:
    unordered_map<int, list<int>> freqCache;
    unordered_map<int, list<int>::iterator> keyLoc;
    unordered_map<int, int> keyFre;
    unordered_map<int, int> data;
    int capacity, minFreq;
    
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(capacity == 0 || keyLoc.count(key) == 0) {
            return -1;
        }
        else {
            freqCache[keyFre[key]].erase(keyLoc[key]);
            if(freqCache[minFreq].empty()) minFreq++;
            keyFre[key]++;
            freqCache[keyFre[key]].push_front(key);
            keyLoc[key] = freqCache[keyFre[key]].begin();
            
            return data[key];
        }
    }
    
    void put(int key, int value) {
        if(capacity > 0) {
            data[key] = value;

            if(keyLoc.count(key) == 0) {
                if(keyLoc.size() == capacity) {
                    int temp = freqCache[minFreq].back();
                    keyLoc.erase(temp);
                    keyFre.erase(temp);
                    freqCache[minFreq].pop_back();
                    if(freqCache[minFreq].empty()) minFreq++;
                }

                keyFre[key]++;
                freqCache[keyFre[key]].push_front(key);
                keyLoc[key] = freqCache[keyFre[key]].begin();
                minFreq = 1;
            }
            else {
                freqCache[keyFre[key]].erase(keyLoc[key]);
                keyFre[key]++;
                freqCache[keyFre[key]].push_front(key);
                keyLoc[key] = freqCache[keyFre[key]].begin();
                if(freqCache[minFreq].empty()) minFreq++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */