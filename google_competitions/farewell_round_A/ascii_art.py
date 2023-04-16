import math

testcase = int(input())

def findGroup(n):
    x = math.floor((n/13)**0.5 -1)

    for i in range(x, x+5):
        if( 13*i*(i+1) >= n): return i

def solve(n):
    grp_num = findGroup(n)

    n-= 13 *(grp_num-1)* grp_num

    if(n % grp_num == 0): return chr(ord('A') -1 + n // grp_num)
    else: return chr(ord('A') + n // grp_num)

for t in range(testcase):
    n = int(input())

    print(f"Case #{t+1}: {solve(n)}")