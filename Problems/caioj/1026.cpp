#include <bits/stdc++.h>
using namespace std;

int cnt;
char stk[30];

bool hui(int x) {
  cnt = 0;
  while (x) {
    stk[++cnt] = x % 10;
    x /= 10;
  }
  for (int i = 1, j = cnt; i < j; i++, j--)
    if (stk[i] != stk[j]) return 0;
  return 1;
}

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    if (hui(i)) 
      cout << i << '\n';
  }
}
