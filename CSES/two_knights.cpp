#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;

    for (long i{1}; i <= n; i++)
    {
        long j{i * i * (i * i - 1) * 0.5 - (4 * (i - 1) * (i - 2))};
        cout << j << "\n";
    }

    return 0;
}
