#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    cout << __cplusplus << endl;

    for (int i = 0; i < 16; i++) {
        if (i % 2 == 1 && s[i] != '0') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}