#include <bits/stdc++.h>
using namespace std;

inline int sum(int x) {
  int k = 0;
  while (x) {
    k += pow(x % 10, 3);
    x /= 10;
  }
  return k;
}

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    if (sum(i) == i)
      cout << i << '\n';
  }
}
