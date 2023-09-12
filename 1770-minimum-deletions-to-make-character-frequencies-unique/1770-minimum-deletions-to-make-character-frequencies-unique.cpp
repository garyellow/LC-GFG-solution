class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26);
        for(auto &&ch : s)
            cnt[ch - 'a']++;
        
        priority_queue<int> greedy;
        for(auto &&i : cnt)
            if(i) greedy.push(i);
        
        int cur = greedy.top(), ans = 0;
        greedy.pop();
        while(greedy.size()) {
            if(greedy.top() >= cur) {
                ans += greedy.top() - cur + 1;
                if(cur > 1) cur--;
            }
            else cur = greedy.top();
            
            greedy.pop();
        }
        
        return ans;
    }
};