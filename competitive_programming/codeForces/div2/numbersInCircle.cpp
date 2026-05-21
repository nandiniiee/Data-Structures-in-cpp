#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t; // t is the number of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n; // n is the number of numbers in the circle
        cin >> n;
        vector<long long int> numbers(n); // numbers  of the cards (1,2,3 etc)
        long long sum = 0;                // sum of the numbers in the circle
        for (int j = 0; j < n; j++)
        {
            cin >> numbers[j];
            sum += numbers[j];
        }
        long long largestNumber = numbers[n - 1];        // largest number in the circle
        long long otherNumbersSum = sum - largestNumber; // sum of the other numbers in the circle
        long long result;
        if (largestNumber > 2 * otherNumbersSum)
        {
            result = 3 * otherNumbersSum;
        }
        else
        {
            result = sum;
        }
        if (result < 3)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << result << endl;
        }
    }
}