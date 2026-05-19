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

const int MAX = 2e5 + 5;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // is there a reason to decrement here?
		a[i]--;
	}

	vector<vector<int>> e(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	// do bfs
	// why bfs?
	// how do we avoid cycles in bfs?
	vector<int> d(n, -infty<int>);
	d[0] = 1;
	vector<vector<int>> idx(MAX);
	for (int i = 0; i < n; i++) {
		idx[a[i]].push_back(i);
	}

	vector<bool> visit(n, false);

	for (int i = 0; i < MAX; i++) {
		sort(idx[i].begin(), idx[i].end(), [&](int x, int y) {
			return d[x] > d[y];
		});
		for (int v : idx[i]) {
			if (!visit[v]) {
				visit[v] = true;
				deque<int> q;
				q.push_back(v);
				while (q.size()) {
					int w = q.front(); q.pop_front();
					for (int x : e[w]) {
						if (!visit[x] && a[x] == a[w]) {
							visit[x] = true;
							d[x] = d[w];
							q.push_back(x);
						}
					}
				}
			}
		}
		for (int v : idx[i]) {
			for (int w : e[v]) {
				if (a[w] > a[v]) {
					d[w] = max(d[w], d[v] + 1);
				}
			}
		}
	}

	cout << max(d[n - 1], 0) << endl;


    return 0;
}