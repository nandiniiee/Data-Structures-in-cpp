#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long y = 1;
        for (int i = 0; i < s.length(); i++)
        {
            y = y * 10;
        }
        cout << y + 1 << endl;
    }
    return 0;
}