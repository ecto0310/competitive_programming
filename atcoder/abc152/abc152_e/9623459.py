// URL: https://atcoder.jp/contests/abc152/submissions/9623459
// Date: Sun, 19 Jan 2020 22:00:48 +0900
// Language: Python3 (3.4.3)
from fractions import gcd

def lcm(x, y):
  return (x * y) // gcd(x, y)

n = int(input())
a = list(map(int,input().split()))
g = a[0]
for i in range(n):
  g = lcm(g,a[i])
ans = 0
for i in range(n):
  ans += g // a[i]
print(ans%1000000007)
