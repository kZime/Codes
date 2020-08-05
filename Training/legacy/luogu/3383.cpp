#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000003;

vector<int> pri;
bitset<maxn> np;

int main() { 
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  np[1] = 1;
  for (int i = 2; i <= n; i++) { 
    if (!np[i]) 
      pri.push_back(i);
    for (int j = 0; j < pri.size(); j++) { 
      int k = pri[j] * i;
      if (k > n) break;
      np[k] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  while (m--) { 
    int k;
    cin >> k;
    if (!np[k]) cout << "Yes\n";
    else cout << "No\n";
  }
}
