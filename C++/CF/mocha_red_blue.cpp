// https://codeforces.com/contest/1559/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count{0};
        cin >> n;
        char arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] == 'R')
            {
                if (arr[i - 1] == '?')
                    arr[i - 1] = 'B';
                if (arr[i + 1] == '?')
                    arr[i + 1] = 'B';
            }
            if (arr[i] == 'B')
            {
                if (arr[i - 1] == '?')
                    arr[i - 1] = 'R';
                if (arr[i + 1] == '?')
                    arr[i + 1] = 'R';
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == '?')
            {
                count++;
                if ((i != 0) && (arr[i - 1] == 'R'))
                    arr[i] = 'B';
                if ((i != n - 1) && (arr[i + 1] == 'R'))
                    arr[i] = 'B';
                if ((i != 0) && (arr[i - 1] == 'B'))
                    arr[i] = 'R';
                if ((i != n - 1) && (arr[i + 1] == 'B'))
                    arr[i] = 'R';
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == '?')
            {
                count++;
                if ((i != 0) && (arr[i - 1] == 'R'))
                    arr[i] = 'B';
                if ((i != n - 1) && (arr[i + 1] == 'R'))
                    arr[i] = 'B';
                if ((i != 0) && (arr[i - 1] == 'B'))
                    arr[i] = 'R';
                if ((i != n - 1) && (arr[i + 1] == 'B'))
                    arr[i] = 'R';
            }
        }

        if (count == 2 * n)
        {
            for (int i = 0; i < n; i += 2)
            {
                arr[i] = 'R';
                arr[i + 1] = 'B';
            }
        }

        for (int i = 0; i < n; i++)
            cout << arr[i];
        cout << "\n";
    }
}