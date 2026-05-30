#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        map<pair<int, int>, int> dp;
        dp[{x, 0}] = 0;

        for (int i = 0; i < n; i++)
        {
            map<pair<int, int>, int> ndp;

            for (auto it : dp)
            {
                int emptyTables = it.first.first;
                int freeSeats = it.first.second;
                int seated = it.second;

                ndp[{emptyTables, freeSeats}] =
                    max(ndp[{emptyTables, freeSeats}], seated);

                if (u[i] == 'I')
                {
                    if (emptyTables > 0)
                    {
                        ndp[{emptyTables - 1, freeSeats + s - 1}] =
                            max(ndp[{emptyTables - 1, freeSeats + s - 1}],
                                seated + 1);
                    }
                }
                else if (u[i] == 'E')
                {
                    if (freeSeats > 0)
                    {
                        ndp[{emptyTables, freeSeats - 1}] =
                            max(ndp[{emptyTables, freeSeats - 1}],
                                seated + 1);
                    }
                }
                else
                {
                    if (freeSeats > 0)
                    {
                        ndp[{emptyTables, freeSeats - 1}] =
                            max(ndp[{emptyTables, freeSeats - 1}],
                                seated + 1);
                    }

                    if (emptyTables > 0)
                    {
                        ndp[{emptyTables - 1, freeSeats + s - 1}] =
                            max(ndp[{emptyTables - 1, freeSeats + s - 1}],
                                seated + 1);
                    }
                }
            }

            dp = ndp;
        }

        int answer = 0;

        for (auto it : dp)
        {
            answer = max(answer, it.second);
        }

        cout << answer << '\n';
    }

    return 0;
}