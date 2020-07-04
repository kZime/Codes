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
