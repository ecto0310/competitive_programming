// URL: https://atcoder.jp/contests/abc194/submissions/20696575
// Date: Sat, 06 Mar 2021 21:09:12 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N), B(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    i64 ans = 1e9;
    for (i64 i = 0; i < N; i++) {
        ans = min(ans, A[i] + B[i]);
        for (i64 j = i + 1; j < N; j++) {
            ans = min(ans, max(A[i], B[j]));
            ans = min(ans, max(A[j], B[i]));
        }
    }
    cout << ans << endl;
    return 0;
}
