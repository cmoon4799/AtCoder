#include <bits/stdc++.h>

using namespace std;

void helper(long long v) {
	if (v > 0) {
		cout << "+" << endl;
	} else if (v == 0) {
		cout << "0" << endl;
	} else {
		cout << "-" << endl;
	}
}

int main() {
	long long N;
	cin >> N;
	vector<long long> a(N), p(N - 1);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	} 
	for (int i = 0; i < N - 1; i++) {
		cin >> p[i];
	}

	vector<int> d(N);
	vector<long long> b(N);
	b[0] = a[0];
	for (int i = 0; i < N - 1; i++) {
		d[i + 1] = d[p[i] - 1] + 1;
		b[d[i + 1]] += a[i + 1];
	}

	long long v = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (b[i] != 0) {
			v = b[i];
			break;
		}
	}

	helper(v);
}
