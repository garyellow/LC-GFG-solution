struct Trie {
    bool last;
    vector<Trie *> alpha = vector<Trie *>(26);
    Trie() : last(false) {}
};

class WordDictionary {
public:
    WordDictionary() {
        Root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = Root;
        for(auto &&i : word)
        {
            if(cur->alpha[i - 'a'] == nullptr) cur->alpha[i - 'a'] = new Trie();
            cur = cur->alpha[i - 'a'];
        }
        cur->last = true;
    }
    
    bool search(string word) {
        return DFS(Root, word, 0);
    }
    
    bool DFS(Trie *root, string word, int index)
    {
        if(index == word.size()) return root->last ? true : false;
        else if(word[index] == '.')
        {
            for(int i = 0; i < 26; i++)
                if(root->alpha[i] != nullptr && DFS(root->alpha[i], word, index + 1))
                    return true;

            return false;
        }
        else
            return root->alpha[word[index] - 'a'] != nullptr && DFS(root->alpha[word[index] - 'a'], word, index + 1);
    }

    Trie *Root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */