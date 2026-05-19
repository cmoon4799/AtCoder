#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
        res = max(j - i, res);
    }

    cout << res << endl;
}