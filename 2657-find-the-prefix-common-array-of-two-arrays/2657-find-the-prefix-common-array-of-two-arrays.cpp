class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> prefix;
        vector<int> C;
        for (int i = 0, cnt = 0; i < A.size(); i++) {
            if (!prefix.count(A[i])) {
                prefix.insert(A[i]);
            } else {
                cnt++;
            }

            if (!prefix.count(B[i])) {
                prefix.insert(B[i]);
            } else {
                cnt++;
            }

            C.emplace_back(cnt);
        }

        return C;
    }
};