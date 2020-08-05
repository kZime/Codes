#include <bits/stdc++.h>
using namespace std;

char str[233333];
int lst[27], ans;
vector<pair<int, int> > pp;

bool judge(pair<int, int> a, pair<int, int> b) { 
  if (b.first < a.first) swap(a, b);
  if (a.second > b.first and a.second < b.second) { 
    // printf("%d %d -- %d %d\n", a.first, a.second, b.first, b.second);
    return true;
  }
  else return false;
}

int main() { 
  // freopen("in", "r", stdin);
  scanf("%s", str + 1);
  for (int i = 1; str[i]; i++) { 
    if (!lst[str[i] - 'a']) lst[str[i] - 'a'] = i;
    else { 
      pp.push_back(make_pair(lst[str[i] - 'a'], i));
      lst[str[i] - 'a'] = 0;
    }
  }
  for (int i = 0; i < pp.size(); i++) { 
    for (int j = i + 1; j < pp.size(); j++) { 
      if (judge(pp[i], pp[j])) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
}
