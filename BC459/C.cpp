#include <bits/stdc++.h>
using namespace std;

vector<int> t;
int base = 1;
vector<int> cells;
int removals = 0;
vector<int> fenwick;
int q;

void build()
{
    int n = cells.size();
    fenwick.resize(q + 5);
    while (base < n)
    {
        base *= 2;
    }
    t.resize(2 * base, 1e6);

    for (int i = 0; i < n; i++)
    {
        t[base + i] = 0;
    }
    for (int i = base - 1; i > 0; i--)
    {
        t[i] = min(t[2 * i], t[2 * i + 1]);
    }
}

void update(int x, int delta)
{
    x += 1;
    int n = fenwick.size();
    while (x < n)
    {
        fenwick[x] += delta;
        x += x & -x;
    }
}

int query(int y)
{
    if (y < 0)
    {
        return 0;
    }
    int n = fenwick.size();
    y = min(y + 1, n - 1);
    int res = 0;
    while (y > 0)
    {
        res += fenwick[y];
        y -= y & -y;
    }

    return res;
}

// add a block to cell x
void add(int node, int i, int j, int x)
{
    if (i == j)
    {
        t[node] += 1;
        return;
    }

    int k = (i + j) / 2;
    if (x <= k)
    {
        add(2 * node, i, k, x);
    }
    else
    {
        add(2 * node + 1, k + 1, j, x);
    }
    t[node] = min(t[2 * node], t[2 * node + 1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> q;

    cells.resize(n);

    build();
    vector<int> res;
    update(0, n);
    while (q--)
    {
        int query_type;
        cin >> query_type;

        if (query_type == 1)
        {
            int x;
            cin >> x;
            x--;
            add(1, 0, base - 1, x);
            cells[x]++;
            update(cells[x], 1);
            update(cells[x] - 1, -1);
            if (t[1] > removals)
            {
                removals++;
            }
        }
        else
        {
            int y;
            cin >> y;
            res.push_back(n - query(y + removals - 1));
        }
    }

    for (auto v : res)
    {
        cout << v << endl;
    }
}