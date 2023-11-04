class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() && right.size())
            return max(*max_element(left.begin(), left.end()),n - *min_element(right.begin(), right.end()));
        else if(left.size())
            return *max_element(left.begin(), left.end());
        else
            return n - *min_element(right.begin(), right.end());
    }
};