#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
const long long MOD = 998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;
        long long phi = MOD - 1; // MOD is prime
        long long nm = (n % phi) * (m % phi) % phi;
        long long cr = max(0LL, n - r + 1) % phi * (max(0LL, m - c + 1) % phi) % phi;
        long long exponent = (nm - cr % phi + phi) % phi;
        cout << power(2, exponent, MOD) << "\n";
    }
    return 0;
}
