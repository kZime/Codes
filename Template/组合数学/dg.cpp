# include <bits/stdc++.h>
using namespace std;
int com(int n, int m) { 
    if(!m) return 1;
    if(n ^ m) { 
        return com(n - 1, m - 1) + com(n - 1, m);
    } else return 1;
}


int C(int n, int m) { // 简化前
    int m1 = 1, n1 = 1, m_n1 = 1; //  m1 -> m!  n1 -> n!  m_n1 -> (m - n)!
    for(int i = 1; i <= m; i++) m1 = m1 * i;
    for(int i = 1; i <= n; i++) n1 = n1 * i;
    for(int i = 1; i <= (m - n); i++) m_n1 = m_n1 * i;
    return m1 / (n1 * m_n1);
}

int C2(int n, int m) { // 简化后
    int son = 1, mom = 1;
    for(int i = n + 1; i <= m; i++) son *= i;
    for(int i = 1; i <= (m - n); i++) mom *= i;
    return son / mom;
}


int main() {
    int n, m;
    cin >> n >> m;
    printf("C: %d\nC2: %d\n", C(n, m), C(n, m));
}
