class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v1, v2;
        
        for(int i = 0; i < img1.size(); i++) {
            for(int j = 0; j < img2.size(); j++) {
                if(img1[i][j]==1)
                    v1.push_back({i,j});
                
                if(img2[i][j]==1)
                    v2.push_back({i,j});
            }
        }
        
        int ans = 0;
        map<pair<int,int>,int> mp;
        
        for(auto &&[i1, j1] : v1) {
            for(auto &&[i2, j2] : v2) {
                int a = i1 - i2;
                int b = j1 - j2;
                mp[{a,b}]++;
                ans = max(ans, mp[{a,b}]);
            }
        }
        
        return ans;
    }
};