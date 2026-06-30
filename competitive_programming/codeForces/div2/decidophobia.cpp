#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
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
        int d;
        cin >> d;
        vector<long long> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        vector<long long> psum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            psum[i + 1] = psum[i] + array[i];
        }
        long long ans = 0;
        long long mult = 2LL * d + 1;
        for (int j = 0; j < n; j++)
        {
            int l0 = ((j - d) % n + n) % n;
            int r0 = (j + d) % n;
            long long W;
            if (l0 <= r0)
            {
                W = psum[r0 + 1] - psum[l0];
            }
            else
            {
                W = (psum[n] - psum[l0]) + psum[r0 + 1];
            }
            long long c = mult * array[j] - W;
            if (c > 0)
            {
                ans += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}