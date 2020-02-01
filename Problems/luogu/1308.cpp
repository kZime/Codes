# include <bits/stdc++.h>
using namespace std;

string str, st;

int main() { 
    getline(cin, st);
    getline(cin, str);
    int a = st.size();
    int b = str.size();
    for(int i = 0; i < a; i++) if(isalpha(st[i])) st[i] = tolower(st[i]);
    for(int i = 0; i < b; i++) if(isalpha(str[i])) str[i] = tolower(str[i]);
    int ans = -1, cnt = 0;
    for(int i = 0; i <= b - a; i++) { 
        if(i && str[i - 1] != ' ') continue;
        if(isalpha(str[i + a])) continue;
        if(str.substr(i, a) == st) { 
            cnt++;
            if(!~ans) ans = i;
        }
    }
    if(!~ans) printf("-1\n");
    else printf("%d %d\n", cnt, ans);
}
