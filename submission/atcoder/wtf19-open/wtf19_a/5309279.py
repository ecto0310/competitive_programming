// URL: https://atcoder.jp/contests/wtf19-open/submissions/5309279
// Date: Wed, 08 May 2019 17:37:47 +0900
// Language: Python3 (3.4.3)
n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = []
now = -1
for i in range(k+1):
    mi = 9999
    pos = 0
    for j in range(n):
        if now != j and a[j] <= mi:
            pos = j
            mi = a[j]
    for j in range(n):
        if j != now and j != pos:
            ans.append(j+1)
            a[j] -= 1
            if a[j] < 0:
                print(-1)
                exit()
    ans.append(pos+1)
    a[pos] -= 1
    if a[pos] < 0:
        print(-1)
        exit()
    now = pos
print(len(ans))
print(*ans)
