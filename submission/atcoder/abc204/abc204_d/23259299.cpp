// URL: https://atcoder.jp/contests/abc204/submissions/23259299
// Date: Sun, 06 Jun 2021 23:18:49 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    i64 N;
    cin >> N;
    vector<i64> T(N);
    i64 sum = 0;
    for (i64 i = 0; i < N; i++) {
        cin >> T[i];
        sum += T[i];
    }
    vector<bool> ok(100001);
    ok[0] = true;
    for (i64 i = 0; i < N; i++) {
        for (i64 j = 100000; 0 <= j - T[i]; j--) {
            if (ok[j - T[i]]) {
                ok[j] = true;
            }
        }
    }
    i64 ans = 1e9;
    for (i64 i = 0; i <= 100000; i++) {
        if (ok[i]) {
            ans = min(ans, max(i, sum - i));
        }
    }
    cout << ans << endl;
    return 0;
}
