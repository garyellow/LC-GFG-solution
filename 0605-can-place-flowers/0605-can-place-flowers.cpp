class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        reverse(flowerbed.begin(), flowerbed.end());
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        
        int all = 0, cur = 0;
        for(auto &&i : flowerbed)
        {
            if(i)
            {
                all += (cur - 1) / 2;
                cur = 0;
            }
            else cur++;
        }
        
        return all >= n;
    }
};