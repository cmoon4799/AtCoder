#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

#define pint pair<int, int>

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
template <typename T>
bool range(T a, T x, T b) {
  return (a <= x) && (x < b);
}

// rational arithmetic
template <typename T>
pair<T, T> add(pair<T, T> a, pair<T, T> b) {
  assert(a.second * b.second != 0);
  T n = a.first * b.second + b.first * a.second, d = a.second * b.second;
  return pair<T, T>(n/gcd(n, d), d/gcd(n, d));
}

template <typename T>
pair<T, T> multiply(pair<T, T> a, pair<T, T> b) {
  assert(a.second * b.second != 0);
  T n = a.first * b.first, d = a.second * b.second;
  return pair<T, T>(n/gcd(n, d), d/gcd(n, d));
}

vector<pint> di{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int h, w;
void bfs(vector<vector<char>>& s, vector<vector<int>>& cc, int count, int i, int j) {
    cc[i][j] = count;
    deque<pint> q{{i, j}};
    while (q.size()) {
        pint f = q.front(); q.pop_front();
        int x = f.first, y = f.second;
        for (pint d : di) {
          if (range<int>(0, x + d.first, h) && range<int>(0, y + d.second, w) && 
            s[x + d.first][y + d.second] == '#' && cc[x + d.first][y + d.second] != count) {
            q.emplace_back(x + d.first, y + d.second);
            cc[x + d.first][y + d.second] = count;
          }
        }        
    }
}

// modular arithmetic
long long inv(long long a, long long p) {
	return a <= 1 ? a : p - (long long)(p / a) * inv(p % a, p) % p;
}

int main() {
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
	long long rc = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
			if (s[i][j] == '.') {
				rc++;
			}
        }
    }

    vector<vector<int>> cc(h, vector<int>(w, 0));
    int count = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '#' && cc[i][j] == 0) {
          count++;
          bfs(s, cc, count, i, j);
        }
      }
    }

    long long ecc = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] != '.') continue;
        set<int> cid;
        for (pint d : di) {
          if (range(0, i + d.first, h) && range(0, j + d.second, w)) {
            if (cc[i + d.first][j + d.second] != 0) {
              cid.insert(cc[i + d.first][j + d.second]);
            }
          }
        }
        ecc = (ecc + count - (cid.size() - 1)) % 998244353;
      }
    }

	long long g = gcd(ecc, rc);
	ecc /= g;
	rc /= g;
	cout << ecc*inv(rc, 998244353) % 998244353 << endl;
}