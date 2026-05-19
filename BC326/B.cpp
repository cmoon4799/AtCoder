#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;


    for (int i = n; i <= 919; i++) {
        int x, y, z;
        x = i/100;
        y = (i - x*100)/10;
        z = i - (i/10)*10;

        if (x*y == z) {
            cout << i << endl;
            return 0;
        }
    }
}