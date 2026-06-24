static int m;
static inline vector<int> operator*(const vector<int>& A,
                                    const vector<int>& B) {
    vector<int> C(m * m, 0);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            if (A[i * m + k] == 0)
                continue;
            for (int j = 0; j < m; j++) {
                C[i * m + j] =
                    (C[i * m + j] + 1LL * A[i * m + k] * B[k * m + j]) %
                    int(1e9 + 7);
            }
        }
    }
    return C;
}
static vector<int> I() {
    vector<int> ans(m * m, 0);
    for (int i = 0; i < m; i++)
        ans[i * m + i] = 1;
    return ans;
}

static vector<int> pow(const vector<int>& M, unsigned m) {
    if (m == 0)
        return I();
    int bMax = 31 - __builtin_clz(m);
    vector<int> ans = M;
    for (int i = bMax - 1; i >= 0; i--) {
        ans = ans * ans;
        if ((m >> i) & 1)
            ans = ans * M;
    }
    return ans;
}

class Solution {
public:
    static int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        vector<int> U(m * m, 0), L(m * m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++)
                U[i * m + j] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                L[i * m + j] = 1;
        }
        n--;
        const int n0 = n >> 1;
        const vector<int> UL = U * L;
        vector<int> P = pow(UL, n0);
        if (n & 1)
            P = L * P;
        return 2LL * reduce(P.begin(), P.end(), 0LL) % int(1e9 + 7);
    }
};