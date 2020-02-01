#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;

typedef pair<int, int> pii;
vector<int> seg;
int n;
string s;
__gnu_cxx::crope str, rstr;
void rev(int st, int ed) { 
    if (st >= ed + 1) return;
    ed++;
    __gnu_cxx::crope tmp = str.substr(st + str.begin(), ed + str.begin());
    str = str.substr(0 + str.begin(), st + str.begin()) + rstr.substr(n - ed + rstr.begin(), n - st + rstr.begin()) + str.substr(ed + str.begin(), str.length() + str.begin());
    rstr = rstr.substr(rstr.begin(), n - ed + rstr.begin()) + tmp + rstr.substr(n - st + rstr.begin(), rstr.length() + rstr.begin());
}

int main() { 
    freopen("unknown.in","r",stdin);
    freopen("unknown.out","w",stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) 
        if (s[i] != '(' and s[i] != ')') 
            str.append(s[i]);
    for (int i = s.length() - 1; i >= 0; i--) 
        if (s[i] != '(' and s[i] != ')') 
            rstr.append(s[i]);
    n = str.length();
    for (int i = 0, cnt = 0; i < s.length(); i++) { 
        if (s[i] != '(' and s[i] != ')') 
            ++cnt;
        if (s[i] == '(')
            seg.push_back(cnt);
        if (s[i] == ')') { 
            rev(*(seg.end() - 1), cnt - 1);
            seg.pop_back();
        }
    }
    cout << str;
}
