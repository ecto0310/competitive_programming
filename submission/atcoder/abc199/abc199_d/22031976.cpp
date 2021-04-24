// URL: https://atcoder.jp/contests/abc199/submissions/22031976
// Date: Sat, 24 Apr 2021 22:28:40 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

vector<vector<i64>> edge;
vector<pair<i64, i64>> p;
vector<i64> c;

i64 dfs(i64 now, i64 n) {
    if (n == 0) {
        return 1;
    }
    vector<i64> cnt(4);
    for (i64 i:edge[p[now].second]) {
        cnt[c[i]]++;
    }
    i64 sum = 0;
    for (i64 i = 1; i <= 3; i++) {
        if (cnt[i] == 0) {
            c[p[now].second] = i;
            sum += dfs(now + 1, n - 1);
        }
    }
    c[p[now].second] = 0;
    return sum;
}

int main() {
    i64 N, M;
    cin >> N >> M;
    edge.resize(N);
    vector<i64> cnt(N);
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
        cnt[A]++;
        cnt[B]++;
    }
    i64 t = 1;
    for (i64 i = 0; i < N; i++) {
        if (cnt[i] == 0) {
            t *= 3;
            continue;
        }
        p.push_back({cnt[i], i});
    }
    sort(p.rbegin(), p.rend());
    c.resize(N, 0);
    cout << dfs(0, p.size()) * t << endl;
    return 0;
}
