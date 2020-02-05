# include <bits/stdc++.h>
using namespace std;

int w[100], a[100], n, cnt = -1;
pair<int, int> tmp[100];

int main() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        w[i] = a[i];
    	tmp[i] = make_pair(a[i], i);
    }
    sort(tmp + 1, tmp + 1 + n);
    for(int i = 1; i <= n; i++) { 
        if(i == 1 || tmp[i].first != tmp[i - 1].first) cnt++;
        a[tmp[i].second] = cnt;
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}
