#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    grid[i].resize(l);
    for (int j = 0; j < l; j++) {
      cin >> grid[i][j];
    }
  }

  int x, y;
  cin >> x >> y;
  x--;
  y--;

  cout << grid[x][y] << endl;
}