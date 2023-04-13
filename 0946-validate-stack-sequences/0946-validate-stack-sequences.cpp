class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int index_push = 0, index_pop = 0;
        while (index_push <= pushed.size())
        {
            if (st.empty() || st.top() != popped[index_pop]) {
                if (index_push == pushed.size()) break;
                st.push(pushed[index_push++]);
            }
            else {
                st.pop();
                index_pop++;
            }
        }

        return st.empty();
    }
};