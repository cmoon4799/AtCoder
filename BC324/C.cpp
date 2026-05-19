#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;

    vector<int> res;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        if (S == T) {
            res.push_back(i);
            continue;
        }

        int q;
        if (S.size() == T.size()) {
            q = 0;
        } else if (S.size() == T.size() - 1) {
            q = 1;
        } else if (S.size() - 1 == T.size()) {
            q = 2;
        } else {
            continue;
        }

        int e = 0, f = 0;
        bool flag = false;
        while (e < T.size() && f < S.size()) {
            if (T[e] == S[f]) {
                e++; f++;
                continue;
            }

            if (flag == true) {
                break;
            }

            if (q == 0) {
                e++; f++;
            } else if (q == 1) {
                e++;
            } else {
                f++;
            }
            flag = true;
        }

        if (e == T.size() && f == S.size()) {
            res.push_back(i);
        } else if (q == 1) {
            if (e == T.size() - 1 && f == S.size()) res.push_back(i);
        } else {
            if (f == S.size() - 1 && e == T.size()) res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for (auto val : res) {
        cout << val + 1 << " ";
    } cout << endl;
}