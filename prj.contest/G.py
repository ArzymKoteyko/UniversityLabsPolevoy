n, k = map(int, input().split())
array = []
r = 0
for i in range(n):
    inp = int(input())
    array.append(inp)
    r = max(r, inp)
r = r + 1
l = -1
while(r-l>1):
    m = (l+r) // 2
    cnt = 0
    for i in array:
        cnt += i//m
    if (cnt < k):
        r=m
    else:
        l=m
print(l)

