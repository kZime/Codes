#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    if (i != 1 and ((i * i) % ((int)pow(10, (int)log10(i) + 1))) == i)
      cout << i << '\n';
  }
}
