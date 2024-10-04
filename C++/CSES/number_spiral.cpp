#include <iostream>
using namespace std;

int main()
{
    long t;
    cin >> t;

    for (int i{0}; i < t; i++)
    {
        long y, x;
        cin >> y;
        cin >> x;

        if (x >= y)
        {
            if (x % 2 != 0)
                cout << x * x - x + 1 + (x - y) << "\n";
            else
                cout << x * x - x + 1 - (x - y) << "\n";
        }
        else
        {
            if (y % 2 == 0)
                cout << y * y - y + 1 + (y - x) << "\n";
            else
                cout << y * y - y + 1 - (y - x) << "\n";
        }
    }

    return 0;
}
