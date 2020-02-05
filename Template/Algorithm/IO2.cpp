#include <bits/stdc++.h>
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *oh = obuf;
std::streambuf *fb;

inline void print(char c) {
    oh == obuf + OUT_LEN ? (fb->sputn(obuf, OUT_LEN), oh = obuf) : 0;
    *oh++ = c;
}
template <class T>
inline void print(T x) {
    static int buf[30], cnt;
    for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
    while (cnt) print((char)buf[cnt--]);
}
inline void flush() { fb->sputn(obuf, oh - obuf); }
#define long long long
const int MAXN = 3000001;
int inv[MAXN];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    fb = std::cout.rdbuf();
    register int n, mod;
    std::cin >> n >> mod;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (long)(mod - mod / i) * inv[mod % i] % mod;
    for (register int i = 1; i <= n; i++) print(inv[i]), print('\n');
    flush();
    return 0;
}
