#include <bits/stdc++.h>
using namespace std;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// int: 32 bits -+ 2**9
// long: 32 or 64 bits depending on the platform
// long: long 64 bits -+ 9**18
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define endl "\n"

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;

// Utility functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

template <typename T>
void print_vector(vector<T> &v)
{
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

// binary exponentiation
ll pow(ll x, ll y, ll MOD = 0)
{
    ll res = 1;
    while (y > 0)
    {
        if (y % 2)
        {
            res *= x;
            if (MOD != 0)
                res %= MOD;
            y -= 1;
        }
        else
        {
            x *= x;
            if (MOD != 0)
                x %= MOD;
            y /= 2;
        }
    }

    return res;
}

vector<int> tree;
vector<int> h;
int base = 1;
void build(int n)
{
    while (base < n)
    {
        base *= 2;
    }

    tree.resize(base * 3, 0);

    for (int i = 0; i < n; i++)
    {
        tree[base + i] = h[i];
    }
    for (int i = base - 1; i > 0; i--)
    {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
}

// v corresponds to [start, end] of tree
// l, r is the target array - we are looking for the leftmost index
// whose building height is at least as large as t
int query_li(int v, int start, int end, int l, int r, int t)
{
    if ((end < l) || (r < start))
    {
        return -1;
    }
    if (start == end)
    {
        if (h[start] >= t)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
    int mid = (start + end) / 2;
    int x = query_li(2 * v, start, mid, l, r, t);
    int y = query_li(2 * v + 1, mid + 1, end, l, r, t);
    if ((x != -1) && (h[x] >= t))
    {
        return x;
    }
    else if ((y != -1) && (h[y] >= t))
    {
        return y;
    }
    return -1;
}

// query the max in the range [l, r]
int query_m(int v, int start, int end, int l, int r)
{
    if ((end < l) || (start > r))
    {
        return 0;
    }

    int mid = (start + end) / 2;
    if ((l <= start) && (end <= r))
    {
        return tree[v];
    }
    int x = query_m(2 * v, start, mid, l, r);
    int y = query_m(2 * v + 1, mid + 1, end, l, r);
    return max(x, y);
}

int32_t main()
{
    FAST_IO
    int n, q;
    cin >> n >> q;
    h.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<int> nb(n); // vector containing length of nondecreasing sequences
    vector<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && h[st.back()] < h[i])
        {
            st.pop_back();
        }

        st.push_back(i);
        nb[i] = st.size();
    }

    // print_vector(h);
    // segment tree
    // for query (l, r) find the building closest to r on its right that
    // is at least as tall as r

    build(n);
    // print_vector(tree);

    // cout << query_m(1, 0, base - 1, 2, 2) << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        // find max in range [l, r]
        int mir = query_m(1, 0, base - 1, l, r);
        // cout << "mir: " << mir << endl;
        // find min ind such that i > r and h[i] >= h[mir]
        int mlm = query_li(1, 0, base - 1, r + 1, n - 1, mir);
        // cout << "mlm: " << mlm << endl;
        // return length of ascending sequence starting from ind
        if (mlm == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << nb[mlm] << endl;
        }
    }
}
