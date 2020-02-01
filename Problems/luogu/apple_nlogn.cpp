# include <bits/stdc++.h>
# define mid ((l + r) >> 1)
using namespace std;
inline int gn() { 
    int k = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

int a[11], h;

int main() { 
    for(int i = 1; i <= 10; i++) a[i] = gn();
    h = gn() + 30;
    sort(a + 1, a + 11);
    int l = 0, r = 10;
    while(l + 1 < r) { 
        if(a[mid] > h) r = mid;
        else l = mid;
    }
    printf("%d\n", l);
}
