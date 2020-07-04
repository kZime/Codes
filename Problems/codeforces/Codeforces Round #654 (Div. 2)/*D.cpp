//
//  main.cpp
//  AACM
//
//  Created by kZime on 2020/7/1.
//  Copyright © 2020 kZime. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int mp[303][303];

int main() {
    // insert code here...
#ifndef ONLINE_JUDGE
    freopen("/Users/Shared/AACM/File", "r", stdin);
#endif
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(mp, 0, sizeof(mp));
//        if (k == 0) {
//            cout << 0 << '\n';
//            continue;
//        }
        int m = k / n, r = k % n;
        vector<pair<int, int> > c;
        for (int i = 1; i <= n; i++)
            c.push_back({0, i});
        for (int i = 1; i <= n; i++) {
            int cnt = m + (i <= r);
            for (auto &cc : c) {
                if (cnt-- > 0) {
                    cc.first++;
                    mp[i][cc.second] = 1;
                    mp[i][0]++;
                    mp[0][cc.second]++;
                }
            }
            sort(c.begin(), c.end());
        }
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
    return 0;
}
/*
 1: 1
 2: 1
 3: 2
 4: 2
 5:
 
 
 100: 50
 100 1+99 2+98 ... 49+51 + 50
 101: 50
 101 1+100 ... 49+52 50+51
 
 
 */
