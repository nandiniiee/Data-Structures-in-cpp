#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;    // t is the number of test cases
    cin >> t; // read the number of test cases
    for (int i = 0; i < t; i++)
    {
        int n; // n is the number of friends alice has
        cin >> n;
        vector<long long> location(n); // location of each friend
        for (int j = 0; j < n; j++)
        {
            cin >> location[j];
        }
        /*sort(location.begin(), location.end());

        int groups = 1;

        for (int i = 1; i < n; i++) {
            if (location[i] != location[i - 1]) {
                groups++;
            }
        }

        cout << groups - 1 << "\n";*/
        sort(location.begin(), location.end());

        int answer = n;

        int k = 0;
        while (k < n)
        {
            long long x = location[k];

            int left = k;

            int j = k;
            while (j < n && location[j] == x)
            {
                j++;
            }

            int right = n - j;

            answer = min(answer, max(left, right));

            k = j;
        }

        cout << answer << '\n';
    }
}
