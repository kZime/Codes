#include <bits/stdc++.h>
using namespace std;

const int maxn = int(1e6 + 2);

int n, m, l[maxn], r[maxn], d[maxn], a[maxn];
int x[maxn];
int tmp[maxn], mp[maxn];

bool judge(int x) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= x; i++) {
        tmp[l[i]] += d[i];
        tmp[1 + r[i]] -= d[i];
    }
    for (int i = 1; i <= n; i++)
        tmp[i] += tmp[i - 1];
    for (int i = 1; i <= n; i++) {
        mp[i] = a[i] - tmp[i];
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("../in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> l[i] >> r[i];
    }
    if (judge(n)) {printf("0\n"); return 0;}
    int s = 1, t = n;
    while (s < t) {
        int mid = (s + t) >> 1;
        if (judge(mid)) {
            s = mid + 1;
        }
        else {
            t = mid;
        }
    }
    cout << -1 << '\n';
    cout << s << '\n';
}