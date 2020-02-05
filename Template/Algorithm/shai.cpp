#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

bool not_pri[maxn];
vector<int> pri;
int mu[maxn], phi[maxn];

void shai_pri(int n) { 
    for (int i = 2; i <= n; i++) { 
        if (!not_pri[i]) { 
            pri.push_back(i);
        }
        for (int j = 0; j < pri.size(); j++) { 
            int k = i * pri[j];
            if (k > n) break;
            not_pri[k] = 1;
        }
    }
}

void shai_mu(int n) { 
    mu[1] = 1;
    for (int i = 2; i <= n; i++) { 
        if (!not_pri[i]) { 
            pri.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; j < pri.size(); j++) { 
            int k = i * pri[j];
            if (k > n) break;
            not_pri[k] = 1;
            if (i % pri[j] == 0) { // (pri[j] ^ 2) | k
                mu[k] = 0;
                break;
            }
            else mu[k] = -mu[i];
        }
    }
}

void shai_phi(int n) { 
    for (int i = 2; i <= n; i++) { 
        if (!not_pri[i]) { 
            pri.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < pri.size(); j++) { 
            int k = pri[j] * i;
            if (k > n) break;
            not_pri[k] = 1;
            if (i % pri[j] == 0) { 
                phi[k] = phi[i] * pri[j];
                break;
            }
            phi[k] = phi[i] * (pri[j] - 1);
        }
    }
}

int main() { 
    shai_phi(1000);
    for (int i = 1; i <= 100; i++) 
        cout << phi[i] << '\n';
}
