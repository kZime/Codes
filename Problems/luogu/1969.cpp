#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, now, ans, pre;
    cin >> n;
    cin >> ans;
    pre = ans;
    for (int i = 2; i <= n; i++) {
        cin >> now;
        if (now > pre) ans += (now - pre);
        pre = now;
    }
    cout << ans << '\n';
}