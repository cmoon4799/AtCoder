#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	long long S;

	cin >> N >> S;
	vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<long long> dp(N + 1, 0);
	// 1. starting from i find j such that [i- j] is a long continguous sequence
	// 2. dp[i] = dp[j + 1] + 1

	vector<long long> ps;
	long long t = 0;
	ps.push_back(0);
	for (int i = 0; i < N; i++) {
		t += a[i];
		ps.push_back(t);
	}

	vector<long long> dps;
	dps.push_back(0);
	long long res = 0;
	for (int i = N - 1; i >= 0; i--) {
		long long ub = S + ps[i];
		int j = upper_bound(ps.begin(), ps.end(), ub) - ps.begin() - 1;
		// [i, j - 1] is a continguous sequence
		// dp[j] + ... + dp[N]
		dp[i] = dp[j] + (N - i);
	}

	for (int i = 0; i < N + 1; i++) {
		res += dp[i];
	}

	cout << res << endl;
}