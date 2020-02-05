#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool IsPrime(int x) { 
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) { 
        if (x % i) continue;
        else return 0;
    }
    return 1;
}

char Max, Min, str[102];
int MaxCnt, MinCnt = 0x7fffffff, Cnt[26];

int main() { 
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    scanf("%s", str);
    for (int i = 0; str[i]; i++) { 
        Cnt[str[i] - 'a']++;
    }
    for (int i = 0; str[i + 1]; i++) { 
        MaxCnt = max(MaxCnt, Cnt[str[i] - 'a']);
        MinCnt = min(MinCnt, Cnt[str[i] - 'a']);
    }
    if (IsPrime(MaxCnt - MinCnt)) { 
        printf("Lucky Word\n%d\n", MaxCnt - MinCnt);
    } else printf("No Answer\n0\n");
}
