<<<<<<< HEAD
def ammount(lenght, array):
    ammount = 0
    for i in range(len(array)):
        ammount += array[i] // lenght
    return ammount


def bin_ser_l (val, array):
    l = 0;
    r = 9223372036854775000;
    while (r-l>1):
        A = ammount((l+r)//2, array)
        if (ammount((l+r)//2, array) < val):
            r = (l+r)//2
        else:
            l = (l+r)//2
    return l



n, k = map(int, input().split())
ropes = [];
for i in range(n):
    ropes.append(int(input()))
print(bin_ser_l(k, ropes))
=======
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
>>>>>>> origin/contest_fix
