// URL: https://www.hackerrank.com/contests/snct-spring20/challenges/alpha-sigma-delta-alpha/submissions/code/1320976222
// Tester
// Language: Python 3
from collections import defaultdict
N = int(input())
d = defaultdict(int)
for i in range(N):
  A,B = list(map(int, input().strip().split()))
  d[A]=max(d[A],B)
ans = 0
for i in d:
  ans+=max(0,d[i])
print(ans)
