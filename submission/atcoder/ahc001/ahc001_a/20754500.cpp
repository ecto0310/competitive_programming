// URL: https://atcoder.jp/contests/ahc001/submissions/20754500
// Date: Sun, 07 Mar 2021 20:30:07 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

i64 getCycle() {
    unsigned int low, high;
    __asm__ volatile("rdtsc"
    : "=a"(low), "=d"(high));
    return ((i64) low) | ((i64) high << 32);
}

i64 xor128() {
    static i64 x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    i64 t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

const double timeLimit = 4.95;
const i64 cyclePerSec = 3000000000;
i64 baseTime;

struct Answer {
    vector<i64> a, b, c, d;
    double score;

    int init(i64 N) {
        a.resize(N);
        b.resize(N);
        c.resize(N);
        d.resize(N);
        return 0;
    }
};

i64 N;
vector<i64> x, y, r;

Answer bestAns, ans;

i64 overlap(i64 x11, i64 x12, i64 x21, i64 x22) {
    i64 l = max(x11, x21), r = min(x12, x22);
    return (r < l ? 0 : r - l);
}

double eval(i64 t, i64 d) {
    double score = ans.score;
    score += 1e9 * (1 - pow(1 - (double) min(r[t], (ans.c[t] - ans.a[t]) * (ans.d[t] - ans.b[t])) /
                                max(r[t], (ans.c[t] - ans.a[t]) * (ans.d[t] - ans.b[t])), 2));
    if (d % 2 == 0) {
        score -= 1e9 * (1 - pow(1 - (double) min(r[t], (ans.c[t] - ans.a[t] - 1) * (ans.d[t] - ans.b[t])) /
                                    max(r[t], (ans.c[t] - ans.a[t] - 1) * (ans.d[t] - ans.b[t])), 2));
    } else {
        score -= 1e9 * (1 - pow(1 - (double) min(r[t], (ans.c[t] - ans.a[t]) * (ans.d[t] - ans.b[t] - 1)) /
                                    max(r[t], (ans.c[t] - ans.a[t]) * (ans.d[t] - ans.b[t] - 1)), 2));
    }
    for (i64 i = 0; i < N; i++)
        if (i != t) {
            if (overlap(ans.a[i], ans.c[i], ans.a[t], ans.c[t]) != 0 &&
                overlap(ans.b[i], ans.d[i], ans.b[t], ans.d[t]) != 0) {
                return -1;
            }
        }
    return score;
}

void init();

void solve() {
    baseTime = getCycle();
    double currentTime = (double) (getCycle() - baseTime) / cyclePerSec;
    double C = timeLimit * 50;
    i64 cnt = 0;
    while (currentTime < timeLimit) {
        if (cnt % 1000000 == 0) {
            init();
        }
        i64 t = xor128() % N, d = xor128() % 4;
        if (d == 0) {
            ans.a[t]--;
            if (ans.a[t] < 0) {
                ans.a[t]++;
                continue;
            }
        } else if (d == 1) {
            ans.b[t]--;
            if (ans.b[t] < 0) {
                ans.b[t]++;
                continue;
            }
        } else if (d == 2) {
            ans.c[t]++;
            if (10000 < ans.c[t]) {
                ans.c[t]--;
                continue;
            }
        } else {
            ans.d[t]++;
            if (10000 < ans.d[t]) {
                ans.d[t]--;
                continue;
            }
        }
        currentTime = (double) (getCycle() - baseTime) / cyclePerSec;
        double forceLine = (timeLimit - currentTime) / C;
        double evalScore = eval(t, d);
        if (evalScore == -1) {
            if (d == 0) {
                ans.a[t]++;
            } else if (d == 1) {
                ans.b[t]++;
            } else if (d == 2) {
                ans.c[t]--;
            } else {
                ans.d[t]--;
            }
            continue;
        }
        if (bestAns.score < evalScore) {
            ans.score = evalScore;
            bestAns = ans;
        } else if (evalScore < ans.score && forceLine < (double) xor128() / LLONG_MAX) {
            if (d == 0) {
                ans.a[t]++;
            } else if (d == 1) {
                ans.b[t]++;
            } else if (d == 2) {
                ans.c[t]--;
            } else {
                ans.d[t]--;
            }
        } else {
            ans.score = evalScore;
        }
        cnt++;
    }
    cerr << "loopCnt; " << cnt << endl;
    return;
}

void init() {
    ans.init(N);
    for (i64 i = 0; i < N; i++) {
        ans.a[i] = x[i];
        ans.b[i] = y[i];
        ans.c[i] = x[i] + 1;
        ans.d[i] = y[i] + 1;
    }
    ans.score = N;
    return;
}

void input() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    r.resize(N);
    for (i64 i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    return;
}

void output() {
    for (i64 i = 0; i < N; i++) {
        cout << bestAns.a[i] << " " << bestAns.b[i] << " " << bestAns.c[i] << " " << bestAns.d[i] << endl;
    }
    cerr << setprecision(9) << bestAns.score / N << endl;
    return;
}

int main() {
    input();
    init();
    solve();
    output();
    return 0;
}
