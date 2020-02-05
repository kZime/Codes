#include <bits/stdc++.h>
using namespace std;
int f[100003], n;
int a[100003], b[100003];
int main() { 
  cin >> n;
  for (int i = 1; i <= n; i++) 
    cin >> a[i];
  for (int i = 1; i <= n; i++) 
    cin >> b[i];
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= n; j++) { 
      if (a[i] == b[j]) f[j] = f[j - 1] + 1;
      else f[j] = max(f[j], f[j - 1]);
    }
  }
  cout << f[n] << '\n';
}
