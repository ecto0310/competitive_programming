// URL: https://atcoder.jp/contests/abc204/submissions/23213093
// Date: Sun, 06 Jun 2021 21:02:24 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        if (10 < A[i]) {
            ans += A[i] - 10;
        }
    }
    cout << ans << endl;
    return 0;
}
