#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("n: %d, k: %d\n", n, k);
  for (int i = 1; i <= k; i++) { 
    printf("i: %d n mod i: %d\n", i, n % i);
  }
}
