// URL: https://atcoder.jp/contests/abc192/submissions/20342764
// Date: Sat, 20 Feb 2021 22:51:45 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string X;
    i64 M;
    cin >> X >> M;
    i64 d = 0;
    if (X.size() == 1) {
        if (X[0] - '0' <= M)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    for (char i:X) {
        d = max(d, (i64) i - '0');
    }
    i64 ng = (i64) 1e18 + 1, ok = d;
    while (1 < ng - ok) {
        i64 mid = (ng + ok) / 2;
        i64 tmp = 0, k = 1;
        for (i64 i = X.size() - 1; 0 <= i && tmp <= M; i--) {
            tmp += (X[i] - '0') * k;
            if ((i64) 1e18 / k < (X[i] - '0') || (i != 0 && (i64) 1e18/ k < mid)) {
                tmp = M + 1;
                break;
            }
            k *= mid;
        }
        if (M < tmp)
            ng = mid;
        else
            ok = mid;
    }
    cout << ok - d << endl;
    return 0;
}
