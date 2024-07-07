def fact1(n,new_n):
    if new_n==1 or new_n==0 :
        return 1
    if new_n==n//2:
        return new_n//2
    return new_n*fact1(n,new_n-1)

def fact2(n):
    if n==1:
        return 1
    return n*fact2(n-1)
for tt in range(int(input())):
    n=int(input())
    fac1 = fact1(n,n)
    if(n>2):
        fac2 = fact2(n//2)
    print(fac1*fac2)