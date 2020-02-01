#include <bits/stdc++.h>
using namespace std;

map<string, bool> alr;
int n, ans;
string str;

int main() { 
  cin >> n;
  for (int i = 1; i <= n; i++) { 
    cin >> str;
    if (!alr.count(str)) { 
      alr[str] = 1;
      ans++;
    }
  }
  cout << ans;
}
