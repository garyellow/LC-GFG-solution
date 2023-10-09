class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        
        int container = INT_MIN;
        while(r > l) {
            container = max(container, (r - l) * min(height[r], height[l]));
            
            if(height[r] > height[l]) l++;
            else r--;
        }
        
        return container;
    }
};