#include <bits/stdc++.h>
using namespace std;

struct st {
    int a, b;
    void equ (int _a, int _b) {
        a = _a;
        b = _b;
    }
    void add(st s, st t) {
        a = s.a + t.a;
        b = s.b + t.b;
    }
}inc[22], sum[22];

int a, b, n, x, m;

int main() {
    cin >> a >> n >> m >> x;
    inc[1].equ(1, 0);
    inc[2].equ(0, 0);
    inc[3].equ(1, 0);
    inc[4].equ(0, 1);
    for (int i = 5; i < n; i++) {
        inc[i].add(inc[i - 2], inc[i - 1]);
    }
    sum[0].equ(0, 0);
    for (int i = 1; i < n; i++) {
        sum[i].add(sum[i - 1], inc[i]);
//        printf("%d: (%d, %d)\n", i, sum[i].a, sum[i].b);
    }
    b = (m - (sum[n - 1].a * a)) / sum[n - 1].b;
    cout << a * sum[x].a + b * sum[x].b << endl;

}