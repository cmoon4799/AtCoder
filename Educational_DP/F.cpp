#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ppint = pair<int, pint>;

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    int i = n;
    int j = m;
    string res;

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            res += s[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}