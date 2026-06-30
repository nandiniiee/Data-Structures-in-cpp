#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<long long> goodNumbers;
bool isGoodnumber(long long n)
{
    bool seen[10] = {0};
    int count = 0;
    while (n > 0)
    {
        int d = n % 10;
        if (!seen[d])
        {
            seen[d] = true;
            count++;
            if (count > 2)
            {
                return false;
            }
        }
        n = n / 10;
    }
    return true;
}

void generateGood(long long cur, int d1, int d2)
{
    if (cur > 1000000000LL)
    {
        return;
    }
    if (cur >= 2)
    {
        goodNumbers.push_back(cur);
    }
    long long next = cur * 10 + d1;
    if (next <= 1000000000LL)
    {
        generateGood(next, d1, d2);
    }
    if (d1 != d2)
    {
        next = cur * 10 + d2;
        if (next <= 1000000000LL)
        {
            generateGood(next, d1, d2);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int d = 1; d <= 9; d++)
    {
        generateGood(d, d, d);
    }
    for (int d1 = 0; d1 <= 9; d1++)
    {
        for (int d2 = d1 + 1; d2 <= 9; d2++)
        {
            if(d1!=0){
                generateGood(d1,d1,d2);
            }
            if(d2!=0){
                generateGood(d2,d1,d2);
            }
        }
    }

    sort(goodNumbers.begin(), goodNumbers.end());
    goodNumbers.erase(unique(goodNumbers.begin(), goodNumbers.end()), goodNumbers.end());

    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        for (long long y : goodNumbers)
        {
            if (isGoodnumber(x * y))
            {
                cout << y << endl;
                break;
            }
        }
    }
    return 0;
}