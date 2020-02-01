//
// Created by kzime on 17-8-24.
//

# include <bits/stdc++.h>
using namespace std;

vector<int> str;

inline bool hui(int x) {
    str.clear();
    while(x) {
        str.push_back(x % 10);
        x /= 10;
    }
    int len = (int) (str.size());
    for(int i = 0; i << 1 < len; i++) {
        if(str[i] ^ str[len - i - 1]) return 0;
    }
    return 1;
}

inline bool pri(int x) {
    for(int i = 3; i * i <= x; i += 2)
        if(x % i) continue;
        else return 0;
    return 1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    a += !(a % 2);
    b = b > 9999999 ? 9999999 : b;
    if (a <= 5) { 
        printf("5\n");
        a = 7;
    }
    if (b >= 11 && a <= 7) { 
        printf("7\n11\n");
        a = max(a, 101);
    }
}
