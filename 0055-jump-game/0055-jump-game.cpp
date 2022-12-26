class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        for (int i = 0, cango = 0; i <= cango; i++)
        {
            cango = max(cango, i + nums[i]);

            if(cango >= nums.size() - 1) return true;
        }

        return false;
    }
};