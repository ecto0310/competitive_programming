N = int(input())
S = input()
ans = 0
for i in S:
  if i=='a' or i=='i' or i=='u' or i=='e' or i=='o':
    ans+=1
print(ans)
