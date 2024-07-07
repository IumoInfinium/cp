def generate(d,l):
    m = max(d)
    tmp = [0] * (m+1)
    for i in range(l):
        tmp[d[i]] += 1
    result = 0
    left = 0
    for i in range(m, 0, -1):
        left += tmp[i]
        if left > 0:
            left -= 1
            result += 1
    return result

for i in range(int(input())):
    n=int(input())
    d=[int(x)  for x in input().split(' ')]
    if n>1:
        d.sort()
        print('Case #'+str(i+1)+': '+str(generate(d,n)))
    else:
        print('Case #'+str(i+1)+': '+str(1))