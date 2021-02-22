// URL: https://atcoder.jp/contests/abc192/submissions/20412236
// Date: Mon, 22 Feb 2021 13:21:31 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
#define endl "\n"
 
struct Edge {
    i64 to, T, K;
};
 
int main() {
    i64 N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--;
    Y--;
    vector<Edge> edge[N];
    for (i64 i = 0; i < M; i++) {
        i64 A, B, T, K;
        cin >> A >> B >> T >> K;
        A--;
        B--;
        edge[A].push_back({B, T, K});
        edge[B].push_back({A, T, K});
    }
    vector<i64> far(N, 1e18);
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
    far[X] = 0;
    que.push({0, X});
    while (que.size()) {
        auto[f, now] = que.top();
        que.pop();
        if (far[now] < f)
            continue;
        for (Edge i:edge[now])
            if (f + (f % i.K == 0 ? 0 : i.K - f % i.K) + i.T < far[i.to]) {
                far[i.to] = f + (f % i.K == 0 ? 0 : i.K - f % i.K) + i.T;
                que.push({far[i.to], i.to});
            }
    }
    if (far[Y] == 1e18)
        cout << -1 << endl;
    else
        cout << far[Y] << endl;
    return 0;
}
