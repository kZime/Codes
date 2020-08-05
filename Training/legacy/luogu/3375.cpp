#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000003;

char a[maxn], b[maxn];

int ne[1000003];

int main() {
    scanf("%s%s", a + 1, b + 1);
    int lenb = strlen(b + 1);
    int lena = strlen(a + 1);
    ne[0] = -1;
    for (int i = 2; i <= lenb; i++) {
        int k = ne[i - 1];
        while (~k and b[k + 1] != b[i]) k = ne[k];
        ne[i] = k + 1;
    }
    for (int i = 1, j = 0; i <= lena; i++) {
        while (~j and a[i] != b[j + 1]) j = ne[j];
        j++;
        if (j == lenb) {
            cout << i - lenb + 1 << '\n';
        }
    }
    for (int i = 1; i <= lenb; i++)
        cout << ne[i] << ' ';
}
