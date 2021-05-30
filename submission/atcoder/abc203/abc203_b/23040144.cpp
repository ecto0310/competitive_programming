// URL: https://atcoder.jp/contests/abc203/submissions/23040144
// Date: Sun, 30 May 2021 21:03:51 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, K;
    cin >> N >> K;
    i64 ans = 0;
    for (i64 i = 1; i <= N; i++) {
        for (i64 j = 1; j <= K; j++) {
            ans += i * 100 + j;
        }
    }
    cout << ans << endl;
    return 0;
}
