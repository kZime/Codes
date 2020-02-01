#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
const int mod = 998244353;
typedef long long ll;
int phi[maxn];
ll pre_phi[maxn];
bitset<maxn> vis;
vector<int> pri;
ll mmod(ll a)
{
    a %= mod;
    a += mod;
    return a % mod;
}
void pre_cal(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            pri.push_back(i), vis[i] = 1, phi[i] = i - 1;
        for (int j = 0; j < pri.size(); ++j)
        {
            ll k = pri[j] * i;
            if (k > n) break;
            vis[k] = 1;
            if (i % pri[j] == 0)
            {
                phi[k] = phi[i] * pri[j];
                break;
            }
            phi[k] = phi[i] * (pri[j] - 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        pre_phi[i] += (pre_phi[i - 1] + phi[i]) % mod, pre_phi[i] %= mod;
}
int main()
{
    int n, m;
    cin >> n >> m;
    pre_cal(max(n, m) + 4);
    ll ans = 0;
    if (n > m) swap(n, m);
    for (int i = 1, lst = 0; i <= n; i = lst + 1)
    {
        lst = min(n / (n / i), m / (m / i));
        ans += 1ll * (n / i) * (m / i) * (pre_phi[lst] - pre_phi[i - 1]);
        mmod(ans);
    }
    cout << ans % mod << endl;
}
/*
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000003;
int n, m, phi[maxn], pphi[maxn], ans;
vector<int> pri;
bitset<maxn> np;

int main() { 
    cin >> n;
    m = n;
    for (int i = 2; i <= max(n, m) + 4; i++) { 
        if (!np[i]) { 
            pri.push_back(i), phi[i] = i - 1;
        }
        for (int j = 0; j < pri.size(); j++) { 
            int k = i * pri[j];
            if (k > n) break;
            np[k] = 1;
            if (i % pri[j] == 0) { 
                phi[k] = phi[i] * pri[j];
                break;
            }
            phi[k] = phi[i] * (pri[j] - 1);
        }
        pphi[i] = pphi[i - 1] + phi[i];
    }
    for (int i = 1; i <= n; i++) { 
        ans += phi[i] * (n / i) * (n / i);
    }
    //for (int i =1, lst = 0; i <= min(n, m); i = lst + 1) { 
        //lst = min(n / (n / i), m / (m / i));
        //ans += (n / i) * (m / i) * (pphi[lst] - pphi[i - 1]); 
    //}
    cout << ans;
}
*/
