// URL: https://atcoder.jp/contests/abc193/submissions/20525205
// Date: Sat, 27 Feb 2021 21:06:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N), P(N), X(N);
    for (i64 i = 0; i < N; i++)
        cin >> A[i] >> P[i] >> X[i];
    i64 ans = 1e10;
    for (i64 i = 0; i < N; i++)
        if (0 < X[i] - A[i])
            ans = min(ans, P[i]);
    if (ans == 1e10)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
