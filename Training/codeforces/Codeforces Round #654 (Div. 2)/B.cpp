//
//  main.cpp
//  AACM
//
//  Created by kZime on 2020/7/1.
//  Copyright © 2020 kZime. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    // insert code here...
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
