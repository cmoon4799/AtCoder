#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    vector<vector<int>> us(N);
    vector<int> cs(N);
    int ms = 0;
    for (int i = 0; i < N; i++) {
        // pick out the unsolved problems
        vector<int> up;

        for (int j = 0; j < M; j++) {
            if (s[i][j] == 'x') {
                up.push_back(a[j]);
            } else {
                cs[i] += a[j];
            }
        }
        int ps = 0;
        sort(up.begin(), up.end(), greater());
        us[i].push_back(0);
        for (int j = 0; j < up.size(); j++) {
            ps += up[j];
            us[i].push_back(ps);
        }

        cs[i] += i + 1;
        ms = max(ms, cs[i]);
    }

    int mc = 0;
    for (int i = 0; i < N; i++) {
        if (cs[i] == ms) {
            mc += 1;
        }
    }

    // do binary search on the prefix sums
    for (int i = 0; i < N; i++) {
        int t = ms - cs[i];

        if (t == 0) {
            cout << (mc == 1 ? 0 : 1) << endl;
            continue;
        }

        // cout << "mc: " << mc << endl;
        // cout << "ms: " << ms << endl;
        // cout << "t: " << t << endl;
        // for (int j = 0; j < M; j++) {
        //     cout << us[i][j] << " " << endl;
        // }
        int k = upper_bound(us[i].begin(), us[i].end(), t) - us[i].begin();
        cout << k << endl;
    }
}