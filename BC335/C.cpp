#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

int main() {
	int n, q;
	cin >> n >> q;
	
	deque<pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		dq.push_back(pair<int, int> (i + 1, 0));
	}

	while (q--) {
		int t;
		cin >> t;

		pair<int, int>  cp = dq.front();
		if (t == 1) {
			char x;
			cin >> x;
			if (x == 'L') {
				dq.push_front(pair<int, int>(cp.first - 1, cp.second));
			} else if (x == 'R') {
				dq.push_front(pair<int, int>(cp.first + 1, cp.second));
			} else if (x == 'U') {
				dq.push_front(pair<int, int>(cp.first, cp.second + 1));
			} else {
				dq.push_front(pair<int, int>(cp.first, cp.second - 1));
			}
			dq.pop_back();
		} else {
			int p;
			cin >> p;
			cout << dq.at(p - 1).first << " " << dq.at(p - 1).second << endl;
		}
	}
}