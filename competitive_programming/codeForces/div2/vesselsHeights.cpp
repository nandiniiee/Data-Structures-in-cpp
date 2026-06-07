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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        vector<long long> ans(n);
        for (int k = 0; k < n; k++)
        {
            vector<long long> e(n);

            for (int i = 0; i < n; i++)
                e[i] = h[(k + i) % n];

            vector<long long> pref(n, 0), suff(n, 0);

            long long cur = 0;
            for (int d = 1; d < n; d++)
            {
                cur = max(cur, e[d - 1]);
                pref[d] = cur;
            }

            cur = 0;
            for (int d = n - 1; d >= 0; d--)
            {
                cur = max(cur, e[d]);
                suff[d] = cur;
            }

            long long res = 0;
            for (int d = 1; d < n; d++)
            {
                res += min(pref[d], suff[d]);
            }

            ans[k] = res;
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}