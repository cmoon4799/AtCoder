#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> s(N);
    vector<long long> c(N);

    for (long long i = 0; i < N; i++) {
        cin >> s[i] >> c[i];
    }

    // map stores all the odd parts
    map<long long, long long> m;
    for (long long i = 0; i < N; i++) {
        int x = s[i], y = c[i];
        long long o = x;
        while (o % 2 == 0) {
            o /= 2;
        }
        m[o] += x*((long long) y)/o;
    }

    long long res = 0;
    for (auto k : m) {
        bitset<64> b = bitset<64>(k.second);
        res += b.count();
    }
    cout << res << endl;
}