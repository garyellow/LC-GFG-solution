class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            st.push(arr[i]);

            while (st.size() && st.top() <= i)
                st.pop();

            if (st.empty())
                cnt++;
        }

        return cnt;
    }
};