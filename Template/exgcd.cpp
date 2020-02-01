# include <bits/stdc++.h>
using namespace std;

int a, b;

void exgcd(int a, int b, int &x, int &y) { 
    if(!b) {x = 1, y = 0; return;}
    exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - (a * y / b);
}

int main() { 
   cin >> a >> b;
   int x, y;
   exgcd(a, b, x, y);
   x = (x % b + b) % b;
   cout << x << endl;
}
