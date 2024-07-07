for _ in range(int(input())):
    n = int(input())
    tarr = list(map(int, input().split()))
    np = tarr[0]
    arr = []
    sm = 1
    for i in range(1, 2*np+1, 2):
        arr.append([tarr[i], tarr[i+1], -1])
        sm += tarr[i+1]
        
    tgroup = list(map(int, input().split()))
    ng = tgroup[0]
    group = []

    for i in range(1, 3*ng+1, 3):
        k = [tgroup[i], tgroup[i+2], tgroup[i+1]]
        group.append(k)

    ans = []
    i = 0
    j = 0
    while i < np and j < ng:
        if arr[i] < group[j]:
            ans.append(arr[i])
            i += 1
        else:
            ans.append(group[j])
            j += 1

    while i < np:
        ans.append(arr[i])
        i += 1

    while j < ng:
        ans.append(group[j])
        j += 1

    def solve(m):
        for item in ans:
            if item[2] == -1:
                m = m-item[1]
            else:
                if item[2] <= m:
                    m += item[1]
        return m
    s = 1
    e = sm
    v = None
    while s <= e:
        m = (s+e)//2
        if solve(m) >= 1:
            v = m
            e = m-1
        else:
            s = m+1
    print(v)
