class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> cnt_t(7);
        vector<int> cnt_b(7);
        vector<int> cnt_s(7);
        
        for(int i = 0; i < tops.size(); i++)
        {
            cnt_t[tops[i]]++;
            cnt_b[bottoms[i]]++;
            if(tops[i] == bottoms[i])
                cnt_s[tops[i]]++;
        }
        
        int minimum = INT_MAX;
        
        for(int i = 0; i < 7; i++)
        {
            if(cnt_t[i] >= 0 && cnt_b[i] - cnt_s[i] >= tops.size() - cnt_t[i])
                minimum = min(minimum, int(tops.size() - cnt_t[i]));
            if(cnt_b[i] >= 0 && cnt_t[i] - cnt_s[i] >= tops.size() - cnt_b[i])
                minimum = min(minimum, int(tops.size() - cnt_b[i]));
        }
        
        return minimum == INT_MAX ? -1 : minimum;
    }
};