class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> u(n);
        iota(u.begin(), u.end(), 0);

        vector<int> in(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                u[find(leftChild[i], u)] = find(i, u);
                in[leftChild[i]]++;
            }
            if(rightChild[i] != -1) {
                u[find(rightChild[i], u)] = find(i, u);
                in[rightChild[i]]++;
            }
        }
        
        for(int i = 0; i < n; i++) u[i] = find(i, u);
        return unordered_set(u.begin(), u.end()).size() == 1 && 
        count(in.begin(), in.end(), 0) == 1 && 
        count(in.begin(), in.end(), 2) == 0;
    }

    int find(int val, vector<int> &u) {
        return val == u[val] ? val : u[val] = find(u[val], u);
    }
};