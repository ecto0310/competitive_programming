// URL: https://atcoder.jp/contests/abc200/submissions/22448021
// Date: Sun, 09 May 2021 02:54:41 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, K;
    cin >> N >> K;
    for (i64 i = 0; i < K; i++) {
        if (N % 200 == 0) {
            N /= 200;
        } else {
            N = N * 1000 + 200;
        }
    }
    cout << N << endl;
    return 0;
}
