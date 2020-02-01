#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415925;

struct point {
    int x, y;
} s, t, p[67];

struct circle {
    int x, y;
    double r;
    circle(int x, int y, double r) : x(x), y(y), r(r) {}
};

vector<circle> alr;
vector<int> xue;
double ans, tempAns;

double dis(int a, int b, int x, int y) {
    return  sqrt((double) (a - x) * (a - x) + (b - y) * (b - y));
}

void check() {
    alr.clear();
    double tmp;
    tempAns = 0;
    unsigned len = xue.size();
    for (int i = 0; i < len; i++) {
        tmp = min(
            abs(p[xue[i]].x - t.x),
            min(
                abs(p[xue[i]].x - s.x),
                min(
                    abs(p[xue[i]].y - t.y),
                    abs(p[xue[i]].y - s.y)
                )
            )
        );
        for (int j = 0; j < alr.size(); j++) {
            tmp = min(
                tmp,
                dis(alr[j].x, alr[j].y, p[xue[i]].x, p[xue[i]].y) - alr[j].r
            );
        }
        if (tmp < 0) tmp = 0;
        alr.push_back(circle(p[xue[i]].x, p[xue[i]].y, tmp));
        tempAns += PI * alr[i].r * alr[i].r;
        ans = max(ans, tempAns);
    }
}

int main() {
    // freopen("in", "r", stdin);
    int n;
    cin >> n;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;
    if (s.x > t.x) swap(s.x, t.x);
    if (s.y > t.y) swap(s.y, t.y);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        // if (p[i].x > t.x or p[i].x < s.x or p[i].y > t.y or p[i].y < s.y) continue;
        xue.push_back(i);
    }
    do {
        check();
    } while (next_permutation(xue.begin(), xue.end()));
    printf("%.0lf", (t.y - s.y) * (t.x - s.x) - ans);
}