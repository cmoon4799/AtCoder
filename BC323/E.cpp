#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }


    // p[t] - probability that a sequence ends at time t
    // more specifically, select songs one at a time
    // what is the probability that this sequence of songs has a switch at time t
    // ans - 1/n x (p[x] + p[x - 1] + ... + p[x - t_1 + 1])
    


    // calculating probability?
    // p[0] - 1

    vector<pair<int, int>> dp(X + 1, pair<int, int>(0, 1));
    dp[0] = pair<int, int>(1, 1);

    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (t[j] <= i) {
                int x = dp[i - t[j]].first, y = dp[i - t[j]].second;
                int e = dp[i].first, f = dp[i].second;
                cout << x << " " << y << " " << e << " " << f << endl;
                // x/yn + e/f
                // xfn + ey, yfn
                dp[i].first = x*f + e*y*N; dp[i].second = y*f*N;
            }
        }
    }

    pair<int, int> res(0, 1);
    for (int i = max(X - t[0] + 1, 0); i <= X; i++) {
        int x = res.first, y = res.second;
        int e = dp[i].first, f = dp[i].second;

        // x/y + e/f
        res.first = x*f + e*y;
        res.second = y*f;
    }

    cout << res.first << " " << res.second;
}