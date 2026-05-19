#include <bits/stdc++.h>

using namespace std;

bool custom(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    int N;

    cin >> N;
    vector<string> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> r(N);
    for (int i = 0; i < N; i++) {
        r[i].second = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i][j] == 'o') {
                r[i].first += 1;
            } else {
                r[j].first += 1;
            }
        }
    }

    sort(r.begin(), r.end(), custom);
    for (auto v : r) {
        cout << v.second + 1 << " ";
    } cout << endl;
}