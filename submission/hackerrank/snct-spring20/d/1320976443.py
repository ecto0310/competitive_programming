import math
Q,X = list(map(int, input().strip().split()))
ans = 0
for i in range(1,int(math.sqrt(X))+1):
  if X % i == 0 and X // i <= Q:
    if X // i == i:
      ans+=1
    else:
      ans+=2
print(ans)
