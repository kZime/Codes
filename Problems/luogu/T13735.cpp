#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;
vector<string> aa, bb;
vector<bool> hs;

bool check() { 
  if (aa.size() ^ bb.size())
    return 0;
  int len = aa.size();
  for (int i = 0; i < len; i++) { 
    if (aa[i][0] != bb[i][0]) return 0;
    int na = 0;
    char now = aa[i][0];
    for (int j = 0; j < aa[i].size(); j++) 
      if (now == aa[i][j]) na++;
    if (na > bb.size()) return 0;
  }
  return 1;
}

int main() { 
  cin >> t;
  while(t--) { 
    aa.clear();
    bb.clear();
    cin >> a;
    int be = 0;
    char now = a[0];
    for (int i = 1; i < (int)a.size(); i++) { 
      if (a[i] != '*' and a[i] != now) { 
        aa.push_back(a.substr(be, i - be));
        be = i;
        now = a[i];
        if (aa.back()[0] == '*') aa.pop_back();
      }
    }
    aa.push_back(a.substr(be, 2333));
    cin >> b;
    be = 0;
    now = b[0];
    for (int i = 1; i < (int)b.size(); i++) { 
      if (b[i] != now) { 
        bb.push_back(b.substr(be, i - be));
        be = i;
        now = b[i];
      }
    }
    bb.push_back(b.substr(be, 2333));
    if (check()) { 
      printf("Yes\n");
    } else printf("No\n");
  }
}
