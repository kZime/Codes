#include <bits/stdc++.h>
using namespace std;

int a[31][31], x = 1, y = 1, t, k = 1, n;
int dx[] = {0, 1, 1, -1};
int dy[] = {1, -1, 0, 1};

int main() {
  cin >> n;
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = 0;
  while (k <= n * n) {
    a[x][y] = k;
    k++;
    if (k > n * n) break;
    while (a[x + dx[t]][y + dy[t]] != 0) {
      t++;
      t %= 4;
    }
    x += dx[t];
    y += dy[t];
    if (t == 0 or t == 2) t++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) { 
      printf("%4d", a[i][j]);
    }
    cout << '\n';
  }
}
