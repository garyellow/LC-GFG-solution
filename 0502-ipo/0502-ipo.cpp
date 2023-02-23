class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++)
            projects.push_back({capital[i], profits[i]});
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maximizeCapital;
        for (int i = 0; k--;) {
            while (i < profits.size() && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};