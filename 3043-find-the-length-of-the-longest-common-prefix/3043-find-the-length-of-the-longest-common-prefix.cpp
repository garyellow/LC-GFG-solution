class Trie {
public:
    vector<Trie*> next;

    Trie() { next = vector<Trie*>(10); }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        auto head = new Trie();
        for (const auto& num : arr1) {
            auto cur = head;
            for (const auto& c : to_string(num)) {
                if (cur->next[c - '0'] == nullptr) {
                    cur->next[c - '0'] = new Trie();
                }

                cur = cur->next[c - '0'];
            }
        }

        int ans = 0;
        for (const auto& num : arr2) {
            int cnt = 0;
            auto cur = head;
            for (const auto& c : to_string(num)) {
                if (cur->next[c - '0'] == nullptr) {
                    break;
                }

                ans = max(ans, ++cnt);
                cur = cur->next[c - '0'];
            }
        }

        return ans;
    }
};