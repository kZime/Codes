
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
struct matrix {
    ll m[103][103], n;
    matrix(ll n) : n(n) {
        memset(m, 0, sizeof(m));
    }
    void input() {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> m[i][j];
            }
        }
    }
    void output() {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cout << m[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void unit() {
        for (ll i = 1; i <= n; i++)
            m[i][i] = 1;
    }
    matrix operator *(const matrix &a) const {
        matrix *ans = new matrix(n);
        ans->n = n;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                for (ll k = 1; k <= n; k++) {
                    (ans->m[i][j] += m[i][k] * a.m[k][j]) %= mod;
                }
            }
        }
        return *ans;
    }
//    void
};

matrix mol(matrix x, ll k) {
    matrix a = *new matrix(x.n);
    a.unit();
    for (; k; k >>= 1) {
        if (k & 1) a = x * a;
        x = x * x;
    }
    return a;
}

int main() {
    ll n, k;
    cin >> n >> k;
    matrix *a = new matrix(n);
    a->input();
    mol(*a, k).output();
}
