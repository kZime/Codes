#include <bits/stdc++.h>
using namespace std;

int n, a[67], maxa, suma, sum;
bool vis[67];

bool dfs(int x, int k, int lst) {
    if (x == n + 1) {
        return (!lst);
    }
    if (lst >= a[x] and !vis[x]) return (vis[x] = 0, dfs(x + 1, k, lst)) or (vis[x] = 1, dfs(x + 1, k, lst - a[x]));
    else return dfs(x + 1, k, lst);
}

int main() {
    freopen("in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        suma += a[i];
    }
    for (int i = maxa; i <= n; i++) {
        if (suma % i) continue;
        memset(vis, 0, sizeof(vis));
        cout << i << ' ';
        for (int j = 1; j <= n; j++) {
            sum = 0;
            if (!vis[j]) dfs(1, i, i);
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) return printf("%d\n", i), 0;
    }
}