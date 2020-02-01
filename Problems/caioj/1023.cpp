#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt = 0, a;
  cin >> a;
  while (a != 1) {
    if (a & 1) a = 3 * a + 1;
    else a >>= 1;
    cnt++;
  }
  cout << cnt;
}
