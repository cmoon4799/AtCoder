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


vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n, 0));

	int x = (n + 1)/2 - 1, y = (n + 1)/2 - 2;
	g[x][y] = 1;
	int di = 0;
	int sl = 1, sc = 0, cc = 1; // sl - side length limit, sc - how many we've filled on the side, cc - current count for side
	for (int i = 0; i < n*n - 2; i++) {
		// move in direction
		x += dx[di]; y += dy[di];
		// write
		g[x][y] = i + 2;
		// turn if necessary
		sc += 1;
		if (sc == sl) {
			cc += 1;
			sc = 0;
			di = (di + 1) % 4;
		}
		if (cc == 2) {
			sl += 1;
			cc = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == (n - 1)/2 && j == (n - 1)/2) {
				cout << "T" << " ";
			} else {
				cout << g[i][j] << " ";
			}
		}
		cout << endl;
	}

    return 0;
}