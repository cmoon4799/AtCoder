#include <bits/stdc++.h>

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
