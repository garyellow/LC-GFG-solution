class Solution {
public:
    string reorganizeString(string s) {
        vector<int> record(26);

        for(auto &&c : s) {
            record[c - 'a']++;
        }

        priority_queue<pair<int, char>> heap;
        for(int i = 0; i < 26; i++) {
            heap.push({record[i], i + 'a'});
        }

        if(heap.top().first > (s.size() + 1) / 2) return "";

        char ch = 0;
        int time = 0;
        for(int i = 0; i < s.size(); i += 2) {
            if(time == 0) {
                auto temp = heap.top();
                time = temp.first;
                ch = temp.second;
                heap.pop();
            }
            s[i] = ch;
            time--;
        }

        for(int i = 1; i < s.size(); i += 2) {
            if(time == 0) {
                auto temp = heap.top();
                time = temp.first;
                ch = temp.second;
                heap.pop();
            }
            s[i] = ch;
            time--;
        }

        return s;
    }
};