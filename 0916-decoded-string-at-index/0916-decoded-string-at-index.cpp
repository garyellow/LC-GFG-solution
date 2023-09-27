class Solution {
public:
    string decodeAtIndex(string s, int k) {
        k--;
        stringstream ss(s);
        vector<pair<string, size_t>> record;
        size_t len = 0;
        while(len <= k) {
            string cur;
            while(isalpha(ss.peek())) {
                char c;
                ss.get(c);
                cur.push_back(c);
            }
            len += cur.size();

            while(isdigit(ss.peek())) {
                char c;
                ss.get(c);
                len *= (c - '0');
            }
            cout << cur << ' ' << len << endl;

            record.push_back({cur, len});
        }

        while(record.size() > 1) {
            auto [cur, len] = record.back();
            record.pop_back();
            auto [last_cur, last_len] = record.back();
            k %= (last_len + cur.size());
            if(k >= last_len) {
                k %= last_len;
                return cur.substr(k, 1);
            }
            k %= last_len;
        }

        k %= record[0].first.size();
        return record[0].first.substr(k, 1);
    }
};