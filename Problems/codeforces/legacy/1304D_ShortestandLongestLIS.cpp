//kZime
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define wi(x) cerr << #x << ": " << x << '\n';
#else
    #define wi(x) 
#endif

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;


template<typename T>
inline T getNum() {
    T k = 0;
    char c = getchar(), f = 1;
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
    return k * f;
}

#define gn() getNum<int>()
#define gl() getNum<ll>()

clock_t opt, edt;
inline void init() {
#ifndef ONLINE_JUDGE
    #pragma warning(suppress : 4996)
    freopen("../input.txt", "r", stdin);
    opt = clock();
#endif
}

inline void tini() {
#ifndef ONLINE_JUDGE
    edt = clock();
    cerr << "\n#" <<  (double)(edt - opt) / CLOCKS_PER_SEC << "s\n";
#endif
}




int n;
char s[(int)2e5 + 5];
bool usd[(int)2e5 + 5];
vector<int> ans;

int main() {
    init();
///////////////////////////////////////////////////////////////////////////////

    int T = gn();
    while (T--) {
        n = gn();
        cin >> s + 1;
        
        ans.clear();
        s[0] = '>';
        memset(usd, 0, sizeof(usd));
        int now = n + 1;
        usd[now] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '<') {
                while (usd[now]) now++;
                ans.push_back(now);
                usd[now] = 1;
            }
            else { // s[i] == '>'
                if (s[i + 1] == '>' or i + 1 == n) {
                    while (usd[now]) now--;
                    ans.push_back(now);
                    usd[now] = 1;
                }
                else { // next is '<'
                    int cnt = 0, k = i + 1;
                    while (s[k] == '<') k++, cnt++;
                    while (cnt--) {
                        while (usd[now]) now--;
                        now--;
                    }
                    usd[now] = 1;
                    ans.push_back(now);
                }
            }
        }
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';


        ans.clear();
        s[0] = '<';
        memset(usd, 0, sizeof(usd));
        now = 0;
        usd[now] = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '>') {
                while (usd[now]) now--;
                ans.push_back(now);
                usd[now] = 1;
            }
            else { // s[i] == '<'
                if (s[i + 1] == '<' or i + 1 == n) {
                    while (usd[now]) now++;
                    ans.push_back(now);
                    usd[now] = 1;
                }
                else { // next is '>' 
                    int cnt = 0, k = i + 1;
                    while (s[k] == '>') k++, cnt++;
                    //now += cnt + 1;
                   
                    while (cnt--) {
                        while (usd[now]) now++;
                        now++;
                    }
                    usd[now] = 1;
                    ans.push_back(now);
                }
            }
        }
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }


///////////////////////////////////////////////////////////////////////////////
    tini();
}

