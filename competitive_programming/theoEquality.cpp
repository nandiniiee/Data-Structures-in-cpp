#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> sequence(n);
        for (int j = 0; j < n; j++)
            cin >> sequence[j];

        vector<pair<int, int>> allPairs;
        allPairs.reserve(n * 65);

        for (int j = 0; j < n; j++)
        {
            int number = sequence[j];
            int countSteps = 0;
            bool seen2 = false;
            bool seen1 = false;

            while (true)
            {
                if (number == 1)
                    seen1 = true;
                if (number == 2)
                    seen2 = true;

                allPairs.push_back({number, countSteps});

                if (number == 1)
                {
                    // only add 2 if we haven't visited 2 yet
                    if (!seen2)
                        allPairs.push_back({2, countSteps + 1});
                    break;
                }
                if (number == 2)
                {
                    // only add 1 if we haven't visited 1 yet
                    if (!seen1)
                        allPairs.push_back({1, countSteps + 1});
                    break;
                }

                if (number % 2 == 0)
                    number /= 2;
                else
                    number += 1;

                countSteps++;
            }
        }

        sort(allPairs.begin(), allPairs.end());

        long long minSteps = 1e18;
        int i = 0;
        int sz = allPairs.size();

        while (i < sz)
        {
            int value = allPairs[i].first;
            long long sumSteps = 0;
            int elemCount = 0;

            while (i < sz && allPairs[i].first == value)
            {
                sumSteps += allPairs[i].second;
                elemCount++;
                i++;
            }

            if (elemCount == n)
                minSteps = min(minSteps, sumSteps);
        }

        cout << minSteps << "\n";
    }

    return 0;
}