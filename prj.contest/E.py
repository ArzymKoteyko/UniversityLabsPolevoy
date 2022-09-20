def day_prod_func(day, a, k, b, m):
    return a*day - (day//k)*a + b*day - (day//m)*b

def bin_srh_l (work, a, k, b, m):
    l = -1;
    r = 9223372036854775806;
    while (r-l>1):
        w = 0;
        if (day_prod_func((l+r)//2, a, k, b, m) < work):
            l = (l+r)//2;
        else:
            r = (l+r)//2;
    return int(r)

a, k, b, m, work = map(int, input().split())
print(bin_srh_l(work, a, k, b, m))