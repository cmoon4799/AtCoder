#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    sort(S.begin(), S.end());
    int res = 0;
    for (int i = 0; i * i < pow(10, N); i++) {
        string T = to_string(i * i);
        T = string(N - T.size(), '0') + T;
        sort(T.begin(), T.end());

        if (S == T) {
            res++;
        }
    }

    cout << res << endl;
}