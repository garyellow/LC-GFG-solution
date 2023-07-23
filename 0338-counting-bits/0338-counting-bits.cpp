class Solution {
public:
    static vector<int> ans;
    
    Solution() {
        if(ans.size() == 1) {
            int time = log2(1e5) + 1;

            while(time--) {
                vector<int> save(ans);

                for(auto &i : save)
                    ans.push_back(i + 1);
            }
        }   
    }
    
    vector<int> countBits(int n) {
        return {ans.begin(), ans.begin() + n + 1};
    }
};

vector<int> Solution::ans = vector<int>({0});