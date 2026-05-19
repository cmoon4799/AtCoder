#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (0 <= (y - x) && (y - x) <= 2 || 0 <= (x - y) && (x - y) <= 3) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}