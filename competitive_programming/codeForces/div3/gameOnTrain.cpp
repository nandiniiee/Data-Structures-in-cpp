#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // t is the number of test cases
    cin >> t;
    while (t--)
    {
        int n; // int n representing the n towers
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        int min = heights[0];
        int max = heights[0];
        for (int i = 1; i < n; i++)
        {
            if (heights[i] < min)
            {
                min = heights[i];
            }
            else if (heights[i] > max)
            {
                max = heights[i];
            }
        }
        int difference = max - min;
        int ans = difference++;
        cout << difference << endl;
    }
}