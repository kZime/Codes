#include <bits/stdc++.h>
using namespace std;

struct Vec {
  int x, y;
  void MakeVec(int a, int b) {
    x = a;
    y = b;
  }
  Vec operator + (const Vec k) {
    Vec a;
    a.x = x + k.x;
    a.y = y + k.y;
    return a;
  }
}v1, v2, v3;

int a, b, c, d, m, n;

int main() {
  cin >> a >> b >> c >> d;
  v1.MakeVec(a, b);
  v2.MakeVec(c, d);
  v3 = v1 + v2;
  cout << '[' << v3.x << ',' << v3.y << "]\n";
}
