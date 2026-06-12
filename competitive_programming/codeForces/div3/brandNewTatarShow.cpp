#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    if (!(cin >> n >> k))
        return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> vals;
    vector<int> counts;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            vals.push_back(a[i]);
            counts.push_back(1);
        }
        else
        {
            counts.back()++;
        }
    }

    int m = vals.size();
    vector<bool> W(m, false);
    vector<int> suffix_false(m + 1, 0);

    int R = m;
    for (int i = m - 1; i >= 0; --i)
    {
        while (R - 1 > i && vals[R - 1] > vals[i] + k)
        {
            R--;
        }

        bool nextL = false;
        if (i + 1 <= R - 1)
        {
            int num_false = suffix_false[i + 1] - suffix_false[R];
            if (num_false > 0)
            {
                nextL = true;
            }
        }

        W[i] = nextL || (counts[i] % 2 == 0);
        suffix_false[i] = suffix_false[i + 1] + (W[i] ? 0 : 1);
    }

    bool can_win = false;
    for (int i = 0; i < m; ++i)
    {
        if (W[i])
        {
            can_win = true;
            break;
        }
    }

    if (can_win)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}