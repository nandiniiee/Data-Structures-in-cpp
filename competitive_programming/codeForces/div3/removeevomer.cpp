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
        /*string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 1; j < s.length(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j == 1 || j != 3)
                    {
                        i++;
                    }
                    else if (j != 1)
                    {
                        for (j; j != i; j--)
                        {
                            t = i;
                            i++;
                            j--;
                            if (s[i] == s[j])
                            {
                                continue;
                            }
                            else
                            {
                                t = i;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
        }*/
        int n;
        cin >> n;
        string s;
        cin >> s;
        int trans = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                trans++;
            }
        }
        if (trans == 2)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
