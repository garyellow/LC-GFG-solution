class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> record;
        
        for(auto &&word : words) {
            record[word]++;
        }
        
        auto cmp = [](pair<int, string> &x, pair<int, string>&y) {
            return x.first == y.first ? x.second > y.second : x.first < y.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> heap(cmp);
        
        for(int i = 0; i < words.size(); i++) {
            if(record[words[i]]) {
                heap.push({record[words[i]], words[i]});
                record[words[i]] = 0;
            }
        }
        
        vector<string> ans;
        while(k--) {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        
        return ans;
    }
};