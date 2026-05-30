#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; // t is the number of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; // n is the length of Alice's cake
        cin >> n;
        vector<long long> heightOfFrosting(n); // height of frosting at position i
        for (int i = 0; i < n; i++)
        {
            cin >> heightOfFrosting[i];
        }
        /*long long prefixSum = 0;
        long long firstHeight = heightOfFrosting[0];

        for (int i = 0; i < n; i++) {
            prefixSum += heightOfFrosting[i];

            long long answer = min(firstHeight, prefixSum / (i + 1));

            cout << answer << " ";
        }

        cout << "\n";*/
        long long prefixSum = 0;
        long long minAvg = 1e18;

        for (int i = 0; i < n; i++)
        {
            prefixSum += heightOfFrosting[i];

            long long average = prefixSum / (i + 1);

            minAvg = min(minAvg, average);

            cout << minAvg << " ";
        }
    }
}