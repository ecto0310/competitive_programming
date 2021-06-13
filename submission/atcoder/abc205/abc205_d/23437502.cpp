// URL: https://atcoder.jp/contests/abc205/submissions/23437502
// Date: Sun, 13 Jun 2021 21:52:39 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, Q;
    cin >> N >> Q;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<pair<i64, i64>> K(Q);
    for (i64 i = 0; i < Q; i++) {
        cin >> K[i].first;
        K[i].second = i;
    }
    sort(K.begin(), K.end());
    vector<pair<i64, i64>> ans(Q);
    i64 now = 0, ind = 0;
    for (i64 i = 0; i < N; i++) {
        if (A[i] <= K[now].first + ind) {
            ind++;
            continue;
        }
        while (now < Q && K[now].first + ind < A[i]) {
            ans[now] = {K[now].second, K[now].first + ind};
            now++;
        }
        if (A[i] <= K[now].first + ind) {
            ind++;
            continue;
        }
    }
    for (; now < Q; now++) {
        ans[now] = {K[now].second, K[now].first + ind};
    }
    sort(ans.begin(), ans.end());
    for (i64 i = 0; i < Q; i++) {
        cout << ans[i].second << endl;
    }
    return 0;
}
