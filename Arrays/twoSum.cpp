#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
/*int main()
{
    Solution s;
    vector<int> nums;
    for (int i = 0; i < nums.size(); i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int target;
    cin >> target;
    s.twoSum(nums, target);
}*/