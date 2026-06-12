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

    int t; // t is the number of test cases
    cin >> t;

    while (t--)
    {
        int n; // n is the length of the binary string
        cin >> n;

        int k; // k is some integer we will be given
        cin >> k;

        string s; // binary string
        cin >> s;

        bool possible = true;

        for (int start = 0; start < k; start++)
        {
            int countOne = 0;

            for (int position = start; position < n; position += k)
            {
                if (s[position] == '1')
                {
                    countOne++;
                }
            }

            if (countOne % 2 != 0)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}