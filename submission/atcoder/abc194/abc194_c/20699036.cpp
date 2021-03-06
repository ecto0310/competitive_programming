// URL: https://atcoder.jp/contests/abc194/submissions/20699036
// Date: Sat, 06 Mar 2021 21:12:55 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<i64, i64> m;
    for (i64 i = 0; i < N; i++)
        m[A[i]]++;
    i64 ans = 0;
    for (i64 i = -200; i <= 200; i++) {
        for (i64 j = i + 1; j <= 200; j++) {
            ans += m[i] * m[j] * (i - j) * (i - j);
        }
    }
    cout << ans << endl;
    return 0;
}
