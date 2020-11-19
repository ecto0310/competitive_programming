N = int(input())
X = list(map(int,input().strip().split()))
X = list(set(X))
X.sort()
ans = [0] * 10
for i in X:
  h = int(str(i)[0])
  b = int(str(i)[-1])
  ans[b] = max(ans[b],ans[h]+i)
print(max(ans))
