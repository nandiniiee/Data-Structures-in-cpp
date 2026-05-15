#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = i + 1; j < strs.size(); j++)
            {
                int k = 0;
                while (k < strs[i].size() && k < strs[j].size() && strs[i][k] == strs[j][k])
                {
                    k++;
                }
                strs[i] = strs[i].substr(0, k);
            }
            return strs[i];
        }
        return "";
    }
};