# include <bits/stdc++.h>
using namespace std;
const long long mike = 1000000007;

inline long long gn() {
    long long k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c =  getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

struct mix {
    long long a[102][102], n;
    mix() {
        memset(a, 0, sizeof(a));
        n = 0;
    }
    mix(long long N) {
        n = N;
        for (long long i = 1; i <= n; i++) {
            for(long long j = 1; j <= n; j++) {
                a[i][j] = gn();
            }
        }
    }
    void output() {
        for(long long i = 1; i <= n; i++) {
            for(long long j = 1; j <= n; j++) {
                printf("%d ", a[i][j]);
            }
            putchar('\n');
        }
    }
    mix operator*(const mix b) const {
        mix c;
        c.n = n;
        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= n; j++) {
                for (long long k = 1; k <= n; k++) {
                    (c.a[i][j] += a[i][k] * b.a[k][j]) %= mike;
                }
            }
        }
        return c;
    }
    mix operator+(const mix b) const {
        mix c;
        c.n = n;
        for(long long i = 1; i <= n; i++) {
            for(long long j = 1; j <= n; j++) {
                (c.a[i][j] += a[i][j] + b.a[i][j]) %= mike;
            }
        }
        return c;
    }
};

mix fast_pow(mix a, long long k) {
    mix b = a, c;
    c = a;
    k--;
    for(; k; k >>= 1) {
        if(k & 1) {
            c = c * b;
        }
        b = b * b;
    }
    return c;
}

long long n, k;

int main() {
    n = gn();
    k = gn();
    mix a(n);
    fast_pow(a, k).output();
}
