#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;

    string s = "";
    string t = "HelloWorld";
    for (int i = 0; i < t.size(); i++)
    {
        if (i + 1 == x)
        {
            continue;
        }
        s += t[i];
    }

    cout << s << endl;
}