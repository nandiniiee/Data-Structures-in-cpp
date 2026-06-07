#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    long long p[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};
    while (t--)
    {
        long long n;
        cin >> n;
        int r = n % 12;
        if (n < p[r])
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << p[r] << ' ' << (n - p[r]) << '\n';
        }
    }

    return 0;
}