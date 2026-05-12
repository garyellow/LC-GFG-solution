class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int max_energy = 0;
        int sum_energy = 0;
        int min_diff_energy = numeric_limits<int>::max();
        for (const auto& task : tasks) {
            sum_energy += task[0];
            max_energy = max(max_energy, task[1]);
            min_diff_energy = min(min_diff_energy, task[1] - task[0]);
        }

        ranges::sort(tasks, [](const auto& x, const auto& y) {
            return x[1] - x[0] > y[1] - y[0];
        });

        int runtime_energy = 0;
        int energy = 0;
        for(const auto& task : tasks) {
            runtime_energy = max(runtime_energy, energy + task[1]);
            energy += task[0];
        }

        return runtime_energy;
    }
};