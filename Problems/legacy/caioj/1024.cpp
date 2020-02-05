#include <bits/stdc++.h>
using namespace std;

int a, b;

int sum(int x) {
  int k = 0;
  for (int i = x - 1; i >= 1; i--) {
    if (x % i == 0) k += i;
  }
  return k;
}
 
int main() {
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    int c = sum(i);
    if (c != i and sum(c) == i) {
      cout << i << ' ';
    }
  }
}
