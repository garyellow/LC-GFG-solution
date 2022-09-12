class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        deque<int> q(tokens.begin(), tokens.end());
        
        sort(q.begin(), q.end());
        int score = 0, ans = 0;
        
        while(q.size() && (power >= q.front() || score)) {
            if(power >= q.front())
            {
                score++;
                power -= q.front();
                q.pop_front();
            }
            else
            {
                score--;
                power += q.back();
                q.pop_back();
            }
            
            ans = max(ans, score);
        }
        
        return ans;
    }
};