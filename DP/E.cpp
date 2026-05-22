#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> a;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a.emplace_back(x, y);
    }

    sort(a.begin(), a.end());
    int DEAD = n + 1;
    int j = m - 1;
    int et = DEAD;
    vector<int> end(n + 2, DEAD);
    for (int day = n - 1; day >= 0; day--)
    {
        while (j >= 0 && a[j].first >= day)
        {
            et = min(et, a[j].second);
            j--;
        }
        if (et != DEAD)
        {
            end[day] = et + 1;
        }
    }

    int LOG = 22;
    vector<vector<int>> bl(n + 2, vector<int>(LOG + 1, DEAD));
    for (int i = 0; i < n + 2; i++)
    {
        bl[i][0] = end[i];
    }

    for (int jump = 1; jump <= LOG; jump++)
    {
        for (int i = 0; i < n + 2; i++)
        {
            bl[i][jump] = bl[bl[i][jump - 1]][jump - 1];
        }
    }

    vector<int> res;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int c = 0;
        int left = x;
        for (int jump = LOG; jump >= 0; jump--)
        {
            if (bl[left][jump] <= y + 1)
            {
                c += (1 << jump);
                left = bl[left][jump];
            }
        }
        res.push_back(c);
    }

    for (auto v : res)
    {
        cout << v << endl;
    }
}