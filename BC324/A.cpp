#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    if (N == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    int x;
    cin >> x;
    for (int i = 0; i < N - 1; i++) {
        int y;
        cin >> y;
        if (y != x) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}