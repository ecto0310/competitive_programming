// URL: https://atcoder.jp/contests/arc119/submissions/22661892
// Date: Sun, 16 May 2021 21:03:25 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    i64 ans = 1e18;
    for (i64 i = 0; i < 64; i++) {
        i64 a = N >> i;
        ans = min(ans, a + i + (N - (a << i)));
    }
    cout << ans << endl;
    return 0;
}
