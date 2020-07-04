//
//  main.cpp
//  AACM
//
//  Created by kZime on 2020/7/1.
//  Copyright © 2020 kZime. All rights reserved.
//

#include <bits/stdc++.h>


int main() {
    // insert code here...
    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::cout << (n + 1) / 2 << '\n';
        
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
