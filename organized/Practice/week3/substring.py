for tt in range(int(input())):
    n=int(input())
    s=input()
    count =0
    for i in s:
        if i=='1':
            count+=1
    count = (count*(count+1))/2
    print(int(count))