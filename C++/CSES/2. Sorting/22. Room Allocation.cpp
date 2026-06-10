#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Customer
{
    int arr, dep, id;
};

signed main()
{
    int n;
    cin >> n;

    vector<Customer> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].arr >> v[i].dep;
        v[i].id = i;
    }

    sort(v.begin(), v.end(), [](const Customer &a, const Customer &b)
         { if (a.arr == b.arr) return a.dep < b.dep; return a.arr < b.arr; });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> rooms(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!pq.empty() && pq.top().first < v[i].arr)
        {
            int room = pq.top().second;
            pq.pop();
            rooms[v[i].id] = room;
            pq.push({v[i].dep, room});
        }
        else
        {
            count++;
            rooms[v[i].id] = count;
            pq.push({v[i].dep, count});
        }
    }

    cout << count << "\n";
    for (int i = 0; i < n; i++)
        cout << rooms[i] << " ";
    cout << "\n";

    return 0;
}
