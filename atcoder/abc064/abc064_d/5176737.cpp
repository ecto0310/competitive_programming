// URL: https://atcoder.jp/contests/abc064/submissions/5176737
// Date: Sun, 28 Apr 2019 21:14:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n;
    string s;
    cin >> n >> s;
    i64 left = 0, p = 0;
    for (i64 i = 0; i < n; i++)
        if (s[i] == '(')
            p++;
        else
        {
            if (p == 0)
                left++;
            else
                p--;
        }
    i64 right = p;
    cout << string(left, '(') << s << string(right, ')') << endl;
    return 0;
}
