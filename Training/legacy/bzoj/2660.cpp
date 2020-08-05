#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt = 2, s[100], n;
vector<ll> fib;
map<pair<ll, ll>, ll> d;

ll dp(ll dep, ll v) { 
    if (v > s[dep]) return 0;
    if (!~dep) return (v == 0);
    if (d.count(make_pair(dep, v))) return d[make_pair(dep, v)];
    ll res = dp(dep - 1, v);
    if (v >= fib[dep]) res += dp(dep - 1, v - fib[dep]);
    return d[make_pair(dep, v)] = res;
}

int main() { 
    cin >> n;
    fib.push_back(1), fib.push_back(2);
    while (true) { 
        vector<ll>::iterator e = fib.end();
        ll now = *(--e) + *(--e);
        if (now <= n) fib.push_back(now);
        else break;
    }
    s[0] = 1;
    short len = fib.size();
    for (short i = 1; i ^ len; i++) 
        s[i] = s[i - 1] + fib[i];
    cout << dp(len - 1, n) << endl;
}
