#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

void dfs(int now, int cnt, int pre) {
    if (cnt == 1) {
        ans++;
        return;
    }
    else {
        for (int i = pre; i <= now / cnt; i++) {
            dfs(now - i, cnt - 1, i);
        }
    }
}

int main() {
    cin >> n >> k;
    dfs(n, k, 1);
    cout << ans << '\n';
}