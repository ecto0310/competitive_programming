// URL: https://atcoder.jp/contests/abc195/submissions/20882603
// Date: Sat, 13 Mar 2021 21:24:58 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    i64 ans = 0, tmp = N, cnt = 0;
    while (tmp) {
        cnt++;
        tmp /= 10;
        if (0 < tmp) {
            ans += (cnt - 1) / 3 * (pow(10, cnt) - pow(10, cnt - 1));
        }
    }
    ans += (cnt - 1) / 3 * (N - pow(10, cnt - 1) + 1);
    cout << ans << endl;
    return 0;
}
