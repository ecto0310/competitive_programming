// URL: https://atcoder.jp/contests/abc198/submissions/21673576
// Date: Sun, 11 Apr 2021 21:53:20 +0900
// Language: C++ (GCC 9.2.1)
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"


vector<i64> C;
vector<vector<i64>> edge;
vector<i64> ans;

void dfs(i64 now, i64 bef, map<i64, i64> &m) {
    if (m[C[now]] == 0) {
        ans.push_back(now + 1);
    }
    m[C[now]]++;
    for (i64 i:edge[now]) {
        if (i != bef) {
            dfs(i, now, m);
        }
    }
    m[C[now]]--;
    return;
}

int main() {
    i64 N;
    cin >> N;
    C.resize(N);
    for (i64 i = 0; i < N; i++) {
        cin >> C[i];
    }
    edge.resize(N);
    for (i64 i = 0; i < N - 1; i++) {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    map<i64, i64> m;
    dfs(0, -1, m);
    sort(ans.begin(), ans.end());
    for (i64 i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
