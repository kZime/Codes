#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    for (int j = i + 1; j <= b; j++) {
      int k = i * i + j * j;
      int c = sqrt(k);
      if (c <= b and c * c == k) {
        cout << i << ' ' << j << ' ' << c << '\n';
      }
    }
  }
}
