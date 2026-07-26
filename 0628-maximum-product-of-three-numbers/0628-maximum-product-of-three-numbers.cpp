class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int a = -1001, b = a, c = b;
        int x = 1001, y = x;

        for (auto& n : A) {
            int pa = a, pb = b, px = x;

            a = max(a, n);
            b = max(b, min(pa, n));
            c = max(c, min(pb, n));

            x = min(x, n);
            y = min(y, max(px, n));
        }

        return max(a * b * c, a * x * y);
    }
};