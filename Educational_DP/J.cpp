#include <bits/stdc++.h>
using namespace std;

struct trio
{
    int first;
    int second;
    int third;
};

int main()
{
    int n;
    cin >> n;

    vector<int> su(n);
    vector<int> bc(4);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> su[i];
        bc[su[i]]++;
        total += su[i];
    }

    // how many are empty
    // how many are not
    // expected number of rolls
    int A = bc[1] + bc[2] + bc[3];
    int B = bc[2] + bc[3];
    int C = bc[3];
    vector<vector<vector<double>>> dp(A + 1, vector<vector<double>>(B + 1, vector<double>(C + 1)));

    // state1 -> state2
    // let p be the probability of hitting a nonempty plate from state 1
    // let E_1 be the expected remaining rolls from state 1
    // let E_2 be the expected remaining rolls from state 2
    // E_1 = 1 + (1 - p)E_1 + pE_2

    vector<vector<trio>> tr(total + 1);
    for (int a = 0; a <= A; a++)
    {
        for (int b = 0; b <= B; b++)
        {
            for (int c = 0; c <= C; c++)
            {
                if (a + 2 * b + 3 * c <= total)
                {
                    tr[a + 2 * b + 3 * c].push_back(trio{a, b, c});
                }
            }
        }
    }

    for (int count = 1; count <= total; count++)
    {
        for (auto [a, b, c] : tr[count])
        {
            dp[a][b][c] = 1;
            if (a > 0)
            {
                dp[a][b][c] += ((double)a / n) * dp[a - 1][b][c];
            }
            if (a < A && b > 0)
            {
                dp[a][b][c] += ((double)b / n) * dp[a + 1][b - 1][c];
            }
            if (b < B && c > 0)
            {
                dp[a][b][c] += ((double)c / n) * dp[a][b + 1][c - 1];
            }
            dp[a][b][c] *= ((double)n / (a + b + c));
        }
    }

    cout << setprecision(10) << dp[bc[1]][bc[2]][bc[3]] << endl;
}