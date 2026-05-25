#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        vector<int> c(26);
        int M = 0;
        char fc;
        for (int i = 0; i < s.size(); i++)
        {
            c[s[i] - 'a']++;
            if (c[s[i] - 'a'] > M)
            {
                fc = s[i];
                M = c[s[i] - 'a'];
            }
        }

        // take max count M
        // sum of counts of all other chars should >= M - 1
        if (s.size() - M < M - 1)
        {
            cout << "No" << endl;
            continue;
        }

        vector<string> buckets(M, string(1, fc));
        int j = 0;
        for (int i = 0; i < 26; i++)
        {
            if ((char)(i + 'a') == fc)
            {
                continue;
            }
            for (int k = 0; k < c[i]; k++)
            {
                buckets[j].push_back((char)(i + 'a'));
                j = (j + 1) % M;
            }
        }

        string res;
        for (int i = 0; i < M; i++)
        {
            res += buckets[i];
        }

        cout << "Yes" << endl;
        cout << res << endl;
    }
}