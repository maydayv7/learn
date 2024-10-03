#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int source, int dest, int via)
{
    if (n == 1)
        cout << source << " " << dest << "\n";
    else
    {
        hanoi(n - 1, source, via, dest);
        hanoi(1, source, dest, via);
        hanoi(n - 1, via, dest, source);
    }
}

int main()
{
    long n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    hanoi(n, 1, 3, 2);
}
