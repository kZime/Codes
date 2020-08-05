#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 3;

int inv[maxn], n, p;

int main() {
    cin >> n >> p;
    inv[1] = 1;
    cout << 1 << '\n';
    for (int i = 2; i <= n; i++) {
        inv[i] = (1ll * (p - p / i) * inv[p % i]) % p;
        cout << inv[i] << '\n';
    } 
}
