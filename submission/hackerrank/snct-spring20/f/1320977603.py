def init_max(init_max_val):
    for i in range(N):
        seg_max[i+num_max-1]=init_max_val[i]    
    for i in range(num_max-2,-1,-1) :
        seg_max[i]=max(seg_max[2*i+1],seg_max[2*i+2]) 
    
def update_max(k,x):
    k += num_max-1
    seg_max[k] = x
    while k:
        k = (k-1)//2
        seg_max[k] = max(seg_max[k*2+1],seg_max[k*2+2])
    
def query_max(p,q):
    if q<=p:
        return ide_ele_max
    p += num_max-1
    q += num_max-2
    res=ide_ele_max
    while q-p>1:
        if p&1 == 0:
            res = max(res,seg_max[p])
        if q&1 == 1:
            res = max(res,seg_max[q])
            q -= 1
        p = p//2
        q = (q-1)//2
    if p == q:
        res = max(res,seg_max[p])
    else:
        res = max(max(res,seg_max[p]),seg_max[q])
    return res

N = int(input())
A = list(map(int,input().strip().split()))
ide_ele_max = -10**10
num_max =2**(N-1).bit_length()
seg_max=[ide_ele_max]*2*num_max
init_max(A)
ans = -10**18
sum = 0
for i in range (N-2):
  sum += A[i]
  ans = max(ans,sum+query_max(i+1,N-1)+A[N-1])
print(ans)
