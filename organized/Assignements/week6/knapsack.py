for _ in range(int(input())):
    n,c,k=map(int,input().split())
    data=list(map(int,input().split()))
    i=0; j=-1
    indices=[0]
    sum=0
    while j<n and i<n:
        if sum>c:
            sum-=data[i]
            i+=1
        elif sum<k:
            j+=1
            if j<n: sum+=data[j]
            else: break
        elif sum>=k and sum<=c:
            indices.append(j-i+1)
            j+=1
            if j<n: sum+=data[j]
            else: break
    print(max(indices))