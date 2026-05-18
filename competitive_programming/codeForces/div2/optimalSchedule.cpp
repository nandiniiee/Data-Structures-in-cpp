//problem statement: 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t; // t is the number of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n; // n is number of students
        long long int a; // a is the cost of individual schedule
        long long int b; // b is the cost of the group schedule
        cin >> n;
        cin >> a;
        cin >> b;
        if (n <= 3)
        {
            if (a * n < b)
            {
                cout << a * n << endl;
            }
            else
            {
                cout << b << endl;
            }
        }
        else
        {
            if (a * 3 <= b)
            {
                cout << a * n << endl;
            }
            else
            {
                cout << min((b * (n / 3) + (n % 3) * a), (b * (n / 3 + 1))) << endl;
            }
        }
    }
}