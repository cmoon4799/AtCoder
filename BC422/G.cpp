#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

// extended Euclidean algorithm
long long egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = (x1 - (a / b) * y1);
    return g;
}

// mod inverse using extended Euclidean algorithm
long long mod_inverse(long long a, long long mod)
{
    long long x, y;
    long long g = egcd(a, mod, x, y);

    assert(g == 1);

    x %= mod;
    if (x < 0)
    {
        x += mod;
    }

    return x;
}

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    // number of solutions to
    // Ai + Bj + Ck = N
    // for a fixed k, compute the number of solutions to Ai + Bj = N - Ck
    // let M = N - Ck
    // a = A/g, b = B/g, m = M/g
    // ai + bj = m
    // for how many t do we have 0 <= i0 + bt <= m/a

    long long res1 = 0;
    long long g = gcd(A, B);
    for (int k = 0; C * k <= N; k++)
    {
        int M = N - C * k;
        if (M % g != 0)
        {
            continue;
        }

        int a = A / g;
        int b = B / g;
        int m = M / g;

        int i0 = (mod_inverse(a, b) * m) % b;
        int bound = m / a;
        cout << "i0, bound: " << i0 << " " << bound << endl;
        bound -= i0;
        bound /= b;
        res1 = (res1 + max(bound, 0) + 1) % MOD;
    }

    cout << res1 << endl;
}