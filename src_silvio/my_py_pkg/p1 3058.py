n = int(input())

barato = 1001

for i in range(n):
    p = 0
    g = 0
    e = 0
    f = 0
    p,g = map(float, input().split())
    g = int(g)
    while e < 1000:
        f = f + p  
        e = e + g
    if f < barato:
        barato = f
print(f'{barato:.2f}')