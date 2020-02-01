#include <bits/stdc++.h>
using namespace std;

long long dp[22][22], n, m, x, y;

inline bool cant(int a, int b) { 
    int p = abs(a - x), q = abs(b - y);
    return (p == 2 && q == 1) || (p == 1 && q == 2) || (!p && !q);
}

int main() { 
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    x++, y++, n++, m++;
    for (int i = 1; i <= m && !cant(1, i); i++) dp[1][i] = 1;
    for (int i = 1; i <= n && !cant(i, 1); i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++) { 
        for (int j = 2; j <= m; j++) { 
            if (!cant(i, j)) dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << " ";
}
