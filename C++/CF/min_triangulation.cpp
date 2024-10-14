// https://codeforces.com/contest/1140/problem/D

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum{0};
    for (long long i = 2; i <= n - 1; i++)
        sum += i * (i + 1);
    cout << sum << '\n';
}
