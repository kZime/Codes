#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, sum = 0;
  scanf("%d", &a);
  while (a) {
    sum += a % 10;
    a /= 10;
  }
  return printf("%d\n", sum), 0;
}
