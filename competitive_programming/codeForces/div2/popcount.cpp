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
        long long n, k;
        cin >> n >> k;

        long long m = 0;
        while (k * ((1LL << (m + 1)) - 1) <= n)
        {
            m++;
        }

        long long used = k * ((1LL << m) - 1);
        long long rem = n - used;

        long long ans = m * k + min(k, rem / (1LL << m));

        cout << ans << '\n';
    }

    return 0;
}
