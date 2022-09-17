struct Trie {
    vector<Trie*> next = vector<Trie*>(26);
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
public:
    Trie root;
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndexes.push_back(i);
            
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new Trie();
            node = node->next[c];
        }
        
        node->index = i;
        node->palindromeIndexes.push_back(i);
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) i++, j--;
        return i >= j;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) add(words[i], i);
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < words.size(); i++) {
            auto s = words[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; j++) {
                if (node->index != -1 && node->index != i && isPalindrome(s, j, s.size() - 1)) ans.push_back({ i, node->index }); 
                node = node->next[s[j] - 'a'];
            }
            
            if (!node) continue;
            for (int j : node->palindromeIndexes) { 
                if (i != j) ans.push_back({ i, j });
            }
        }
        return ans;
    }
};