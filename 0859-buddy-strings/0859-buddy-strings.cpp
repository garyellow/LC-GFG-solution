class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s == goal){
            unordered_set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size();
        }

        int i = 0, j = s.size() - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};