#include <bits/stdc++.h>
using namespace std;

struct crs {
    int x, y, k;
} cr[21];

int n, d;

int check(int x, int y) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(cr[i].x - x) <= d and abs(cr[i].y - y) <= d) {
            res += cr[i].k;
        }
    }
    return res;
}

int main() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++) {
        crs *s = cr + i;
        cin >> s->x >> s->y >> s->k;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i <= 128; i++) {
        for (int j = 0; j <= 128; j++) {
            int tmp = check(i, j);
            if (tmp > ans) {
                ans = tmp;
                cnt = 1;
            }
            else if (tmp == ans) {
                cnt++;
            }
        }
    }
    cout << cnt << ' ' << ans << '\n';
}