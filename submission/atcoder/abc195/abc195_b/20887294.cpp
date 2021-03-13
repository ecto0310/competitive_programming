// URL: https://atcoder.jp/contests/abc195/submissions/20887294
// Date: Sat, 13 Mar 2021 21:39:04 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B, W;
    cin >> A >> B >> W;
    i64 ansMin = 1e9, ansMax = 0;
    for (i64 i = 1; i <= 1000000; i++) {
        double ave = (double) W * 1000 / i;
        if (A <= ave && ave <= B) {
            ansMin = min(ansMin, i);
            ansMax = max(ansMax, i);
        }
    }
    if (ansMin == 1e9 && ansMax == 0) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        cout << ansMin << " " << ansMax << endl;
    }
    return 0;
}
