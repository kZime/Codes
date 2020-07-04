## 0x0. 总结（PS）

时隔一万年重新打了一波，rating--，主要背锅点是D题差一点A出来，大概总结一下每道题的思路吧。

## 0x1 [A - Magical Sticks](https://codeforces.com/contest/1371/problem/A)

这题没什么说的直接贪心，$1+(n-1)、2+(n-2)...$

```cpp
int t, n;
std::cin >> t;
while (t--) {
  std::cin >> n;
  std::cout << (n + 1) / 2 << '\n';
}
```



## 0x2 [B - Magical Calendar](https://codeforces.com/contest/1371/problem/B)

注意一下同一个图形旋转之后算另一种，也要算数。然后当$k \lt n$时对于每一个$k$，都有$k$种结果，$k=n$时算一种，然后就没了。

```cpp
int t, n, r;
cin >> t;
while (t--) {
  cin >> n >> r;
  if (n <= r) {
    cout << 1ll * n * (n - 1) / 2 + 1 << '\n';
  } else {
    cout << 1ll * r * (1 + r) / 2 << '\n';
  }
}
```

## 0x3 [C - A Cookie for You](https://codeforces.com/contest/1371/problem/C)

有点抽象的一道题，

客人1:什么多吃什么，一样就吃Chocolate.

客人2:什么少吃什么，一样就吃Vanilla.

如果客人想吃的没了就崩溃。

简单判断一下就完了。

```cpp
long long t, a, b, m, n;
cin >> t;
while (t--) {
  cin >> a >> b >> m >> n;
  long long tmp = min(m, n);
  a -= tmp;
  m -= tmp;
  b -= tmp;
  n -= tmp;
  if (a < 0 or b < 0) cout << "No\n";
  else {
    if (m == 0) {
      if (n > min(a, b)) cout << "No\n";
      else cout << "Yes\n";
    } else { // n == 0
      if (m > a + b) cout << "No\n";
      else cout << "Yes\n";
    }
  }
}
```

## 0x4[* D - Grid-00100](https://codeforces.com/contest/1371/problem/D)

也算贪心吧，先把所有1分配到所有行，然后放到时候每次放在含1最少的列里。比赛的时候因为$k=0$的情况没处理太好`WA2`了惨惨惨。。

```cpp
int t, n, k;
int mp[303][303];
cin >> t;
while (t--) {
  cin >> n >> k;
  memset(mp, 0, sizeof(mp));
  int m = k / n, r = k % n;
  vector<pair<int, int> > c;
  for (int i = 1; i <= n; i++)
    c.push_back({0, i});
  for (int i = 1; i <= n; i++) {
    int cnt = m + (i <= r);
    for (auto &cc : c) {
      if (cnt-- > 0) { // 死在这里
        cc.first++;
        mp[i][cc.second] = 1;
        mp[i][0]++;
        mp[0][cc.second]++;
      }
    }
    sort(c.begin(), c.end());
  }
  
  // output 
  int mx = 0, mi = 0x7fffffff, ans;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, mp[i][0]);
    mi = min(mi, mp[i][0]);
  }
  ans = pow(mx - mi, 2);
  mx = 0;
  mi = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, mp[0][i]);
    mi = min(mi, mp[0][i]);
  }
  ans += pow(mx - mi, 2);
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << mp[i][j];
    }
    cout << '\n';
  }
}

```

## 0x5 