// URL: https://atcoder.jp/contests/abc203/submissions/23047459
// Date: Sun, 30 May 2021 21:09:37 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, K;
    cin >> N >> K;
    vector<pair<i64, i64>> t(N);
    for (i64 i = 0; i < N; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());
    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        if (ans + K < t[i].first) {
            break;
        }
        K -= t[i].first - ans;
        ans = t[i].first;
        K += t[i].second;
    }
    cout << ans + K << endl;
    return 0;
}
