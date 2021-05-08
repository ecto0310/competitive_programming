// URL: https://atcoder.jp/contests/abc200/submissions/22448253
// Date: Sun, 09 May 2021 03:10:34 +0900
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
    N = min(N, 8LL);
    vector<i64> p(200, -1);
    for (i64 bit = 1; bit < (1LL << N); bit++) {
        i64 sum = 0;
        for (i64 i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                (sum += A[i]) %= 200;
            }
        }
        if (p[sum] == -1) {
            p[sum] = bit;
        } else {
            cout << "Yes" << endl;
            i64 x = 0, y = 0;
            for (i64 i = 0; i < N; i++) {
                if (p[sum] & (1LL << i)) {
                    x++;
                }
                if (bit & (1LL << i)) {
                    y++;
                }
            }
            cout << x;
            for (i64 i = 0; i < N; i++) {
                if (p[sum] & (1LL << i)) {
                    cout << " " << i + 1;
                }
            }
            cout << endl << y;
            for (i64 i = 0; i < N; i++) {
                if (bit & (1LL << i)) {
                    cout << " " << i + 1;
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
