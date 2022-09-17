# def solve(a):
#     return a ^ 2**a.bit_length() -1

def solve(A):
    if A%2 == 0:
        return 1
    else:
        while True:
            B = 2
            if A+B == A^B:
                return B
            B *= 2
t=int(input())
for _ in range(t):
    a= int(input())
    print(solve(a))