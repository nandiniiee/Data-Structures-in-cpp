#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> array(n);
        long long XORSum = 0;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            XORSum ^= array[i];
        }
        
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        
        if (XORSum == 0) {
            cout << 1 << "\n";
        } else {
            int k = 63 - __builtin_clzll(XORSum); // highest bit of xorSum
            long long count = 0;
            for (int i = 0; i < n; i++) {
                if ((array[i] >> k) & 1) count++;
            }
            cout << count % MOD << "\n";
        }
    }
    
    return 0;
}