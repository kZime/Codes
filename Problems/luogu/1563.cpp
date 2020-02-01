#include <bits/stdc++.h>
using namespace std;

string nam[100003];
bool i_o[100003];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> i_o[i] >> nam[i];
    }
    int now = 0;
    for (int i = 1; i <= m; i++) {
        bool l_r;
        int x;
        cin >> l_r >> x;
        if (l_r ^ i_o[now]) { // 逆时针
            now += x;
        } else {
            now = now - x % n + n;
        }
        now %= n;
    }
    cout << nam[now] << '\n';
}