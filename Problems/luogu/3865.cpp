#include <bits/stdc++.h>
using namespace std;

char buf[(int) 2e7], *fs = buf;

inline int gn() {
    int k = 0, f = 1;
    char c = *fs++;
    for (; !isdigit(c); c = *fs++) if (c == '-') f = -1;
    for (; isdigit(c); c = *fs++) k = k * 10 + c - '0';
    return k * f;
}

const int maxn = 100003;

int st[maxn][20], n, m, lg[maxn];

void init() {
    for (int i = 1; i <= lg[n]; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}

int ask(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    //freopen("../in", "r", stdin);
    fread(buf, 1, 2e7, stdin);
    n = gn(), m = gn();
    int tmp = 2, cnt = 0;
    for (int i = 1; i <= n; i++) {
        st[i][0] = gn();
        lg[i] = cnt;
        if (i + 1 == tmp) {
            tmp <<= 1;
            cnt++;
        }
    }
    init();
    int l, r;
    while (m--) {
        l = gn(), r = gn();
        cout << ask(l, r) << '\n';
    }
}
