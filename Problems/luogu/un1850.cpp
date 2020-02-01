#include <bits/stdc++.h>
using namespace std;

int n, m, e, v;
double f[2017][2017];
int c[2017], d[2017];
double k[2017], dp[2017][2017][2];

void init() {
  cin >> n >> m >> v >> e;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i <= n; i++)
    cin >> d[i];
  for (int i = 1; i <= n; i++)
    cin >> k[i];
  memset(f, 0x3f, sizeof(f));
  for (int i = 1, s, t, w; i <= e; i++) {
    cin >> s >> t >> w;
    f[s][t] = w;
    f[t][s] = w;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j][0] = 0x3f3f3f3f;
      dp[i][j][1] = 0x3f3f3f3f;
    }
  }
}

void floyd() {
  for (int i = 1; i <= v; i++)
    f[i][i] = 0;
  for (int k = 1; k <= v; k++) 
    for (int i = 1; i <= v; i++) 
      for (int j = 1; j < i; j++) 
        if (f[i][j] > f[i][k] + f[k][j]) { 
          f[i][j] = f[i][k] + f[k][j];
          f[j][i] = f[i][j];
        }
  //for (int i = 1; i <= v; i++) { 
    //for (int j = 1; j <= v; j++) 
      //cout << f[i][j] << ' ';
    //putchar('\n');
  //}
}

int main() {
  init();
  floyd();
  dp[1][0][0] = 0.0;
  dp[1][1][1] = 0.0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= i and j <= m; j++) {
      double cc = f[c[i - 1]][c[i]];
      double cd = f[c[i - 1]][d[i]];
      double dc = f[d[i - 1]][c[i]];
      double dd = f[d[i - 1]][d[i]];
      dp[i][j][0] = min(
          dp[i - 1][j][0] + 
          cc * 1.0,
          dp[i - 1][j][1] + 
          cc * (1.0 - k[i - 1]) + 
          dc * k[i - 1]
      );
      if (j >= 1)
        dp[i][j][1] = min(
            dp[i - 1][j - 1][0] + 
            cd * k[i] + cc * (1.0 - k[i]), 
            dp[i - 1][j - 1][1] + 
            cc * (1.0 - k[i - 1]) * (1.0 - k[i]) + 
            cd * (1.0 - k[i - 1]) * k[i] + 
            dc * k[i - 1] * (1.0 - k[i]) + 
            dd * k[i - 1] * k[i]
        );
    }
  }
  double res = 0x3fffffff;
  for (int j = 0; j <= m; j++) 
    for (int k = 0; k <= 1; k++) 
      res = min(res, dp[n][j][k]);
  printf("%.2f\n", res);
}
