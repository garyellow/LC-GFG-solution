class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> right(height.size()), left(height.size());
        
        for(int i = 0, l = 0, r = 0; i < height.size(); i++) {
            right[i] = l = max(l, height[i]);
            left[height.size() - 1 - i] = r = max(r, height[height.size() - 1 - i]);
        }
        
        int cnt = 0;
        for(int i = 0; i < height.size(); i++)
            cnt += min(right[i], left[i]) - height[i];
        
        return cnt;
    }
};