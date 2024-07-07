def is_prime(x):
    for i in range(2,int(x**0.5)+1):
        if x%i==0:
            return False
            break
    else:
        return True

def prev_prime(x):
    if x==2:
        return 2
    else:
        for a in range(x-1,2,-1):
            if is_prime(a):
                return a
            
            
a,b=list(map(int,input().split()))

x=prev_prime(a)
y=prev_prime(b)
print(x,y)
print(x-y)