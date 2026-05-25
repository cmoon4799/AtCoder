#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    long long res = 0;
    // 16, 17, 18, 19
    for (int i = 0; i < n; i++)
    {
        char x = s[i][0];
        long long y = x - 'a';
        if (15 <= y && y <= 18)
        {
            y = 7;
        }
        else if (19 <= y && y <= 21)
        {
            y = 8;
        }
        else if (22 <= y && y <= 25)
        {
            y = 9;
        }
        else
        {
            y /= 3;
            y += 2;
        }
        res *= 10;
        res += y;
    }

    cout << res << endl;
}