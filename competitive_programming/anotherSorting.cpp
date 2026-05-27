#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        long long k = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {

                long long diff = a[i] - a[i + 1];

                if (diff > k)
                {
                    k = diff;
                }
            }
        }

        bool possible = true;

        int prev = 0; 

        for (int i = 0; i < n - 1; i++)
        {

            bool found = false;

            for (int cur = 0; cur <= 1; cur++)
            {

                long long left = a[i] + (prev ? k : 0);
                long long right = a[i + 1] + (cur ? k : 0);

                if (left <= right)
                {
                    prev = cur;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}