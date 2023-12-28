n = int(input())
p = []
for i in range(n):
    p.append(list(map(int, input().split())))
a = [p[i][0] for i in range(len(p))]
b = [p[i][1] for i in range(len(p))]
c = [p[i][2] for i in range(len(p))]
d = [0] * (n+1)
d[1] = a[0]
if n > 1:
    d[2] = min(a[0]+a[1], b[0])
if n > 2:
    d[3] = min(d[2]+a[2], d[1]+b[1], c[0])
for i in range(n+1):
    if i >= 4:
        d[i] = (min(d[i-1]+a[i-1], d[i-2]+b[i-2], d[i-3]+c[i-3]))
print(d[n])