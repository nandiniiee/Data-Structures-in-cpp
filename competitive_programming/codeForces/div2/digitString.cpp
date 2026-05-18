#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t; // t is the number of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s; // s has the digit string having digits from 1 to 4
        cin >> s;
        int final = s.size();
        // time limit exceeded (the below code exceeded 2s time limit)
        /*for (int j = 0; j <= s.size(); j++)
        {
            int notRemove = 0;
            for (int k = 0; k < j; k++)
            {
                if (s[k] == '2')
                {
                    notRemove++;
                }
            }
            for (int k = j; k < s.size(); k++)
            {
                if (s[k] == '3' || s[k] == '1')
                {
                    notRemove++;
                }
            }
            int remove = s.size() - notRemove;
            final = min(remove, final);
        }
        cout << final << endl;*/

        // prefix and suffix sum usage to optimize the above code
        vector<int> noOfTwo(s.size() + 1, 0);
        vector<int> noOfOneThree(s.size() + 1, 0);
        for (int j = 0; j < s.size(); j++)
        {
            noOfTwo[j + 1] = noOfTwo[j];
            if (s[j] == '2')
            {
                noOfTwo[j + 1]++;
            }
        }
        for (int j = s.size() - 1; j >= 0; j--)
        {
            noOfOneThree[j] = noOfOneThree[j + 1];
            if (s[j] == '1' || s[j] == '3')
            {
                noOfOneThree[j]++;
            }
        }
        for (int j = 0; j <= s.size(); j++)
        {
            int notRemove = noOfTwo[j] + noOfOneThree[j];
            int remove = s.size() - notRemove;
            final = min(remove, final);
        }
        cout << final << endl;
    }
}