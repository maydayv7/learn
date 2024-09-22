#include <iostream>
using namespace std;

int main()
{
    long n, sum{0};
    cin >> n;

    for (long i{1}; i < n; i++)
    {
        long j{0};
        cin >> j;
        sum += j;
    }

    cout << n * (n + 1) * 0.5 - sum;
    return 0;
}
