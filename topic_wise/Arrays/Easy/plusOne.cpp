#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                if (i == 0)
                {
                    digits[i] = 1;
                    digits.push_back(0);
                }
                else
                {
                    digits[i] = 0;
                }
            }
        }
        // digits.push_back(1);
        return digits;
    }
};