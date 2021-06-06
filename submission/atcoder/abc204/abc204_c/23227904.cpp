// URL: https://atcoder.jp/contests/abc204/submissions/23227904
// Date: Sun, 06 Jun 2021 21:13:25 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> edge[N];
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        queue<i64> que;
        vector<bool> vis(N);
        que.push(i);
        vis[i] = true;
        ans++;
        while (que.size()) {
            i64 p = que.front();
            que.pop();
            for (i64 j:edge[p]) {
                if (!vis[j]) {
                    que.push(j);
                    vis[j] = true;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
