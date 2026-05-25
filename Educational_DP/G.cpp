#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    vector<int> in(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        in[y]++;
    }

    vector<int> dp(n);
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (in[i] == 0)
        {
            q.push_back(i);
        }
    }

    while (q.size())
    {
        int c = q.front();
        q.pop_front();

        for (auto neighbor : e[c])
        {
            dp[neighbor] = max(dp[neighbor], 1 + dp[c]);
            in[neighbor]--;
            if (in[neighbor] == 0)
            {
                q.push_back(neighbor);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}