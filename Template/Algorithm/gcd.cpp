
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) swap(a %= b, b);
    return a;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
}
