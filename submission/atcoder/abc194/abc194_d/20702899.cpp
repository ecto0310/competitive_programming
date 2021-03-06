// URL: https://atcoder.jp/contests/abc194/submissions/20702899
// Date: Sat, 06 Mar 2021 21:19:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    double ans = 0;
    for (i64 i = 1; i < N; i++) {
        ans += (double) N / i;
    }
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}
