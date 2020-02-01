# include <bits/stdc++.h>
# define MAXN 102
using namespace std;

int n, m, a[MAXN][MAXN], f[MAXN][MAXN];

int main() {
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
    f[1][1] = a[1][1];
	for(int i = 1; i <= n; i++) {
        f[i][1] = f[i - 1][1];
		for(int j = 1; j <= m; j++) {
			for(int k = 0; k <= j; k++) {
				f[i][j] = max(f[i][j], f[i - 1][j - k] + a[i][k]);
			}
		}
	}
	printf("%d\n", f[n][m]);
}
