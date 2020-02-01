#include <bits/stdc++.h>
using namespace std;

int a[101], n, sum, arv, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    arv = sum / n;
    for (int i = 1; i <= n; i++) {
        a[i] -= arv;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) continue;
        a[i + 1] += a[i];
        ans++;
    }
    cout << ans << '\n';
    return 0;
}