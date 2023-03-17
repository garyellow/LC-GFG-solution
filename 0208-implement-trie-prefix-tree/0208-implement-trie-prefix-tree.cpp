class TrieNode {
public:
    bool val;
    vector<TrieNode *> next = vector<TrieNode *>(26);  
};

class Trie {
public:
    TrieNode *root = new TrieNode();
    
    Trie() {
        
    }
    
    void insert(string word) { 
        auto temp = root;
        
        for(auto &&ch : word) {
            if(!(temp->next[ch - 'a'])) temp->next[ch - 'a'] = new TrieNode();
            temp = temp->next[ch - 'a'];
        }
        
        temp->val = true;
    }
    
    bool search(string word) {
        auto temp = root;
        
        for(auto &&ch : word) {
            if(!(temp->next[ch - 'a'])) return false;
            temp = temp->next[ch - 'a'];
        }
        
        return temp->val;
    }
    
    bool startsWith(string prefix) {
        auto temp = root;
        
        for(auto &&ch : prefix) {
            if(!(temp->next[ch - 'a'])) return false;
            temp = temp->next[ch - 'a'];
        }
        
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */