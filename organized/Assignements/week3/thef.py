# for _ in range(int(input())):
#     n,m=input().split(" ")
#     if n==m:
#         print("Yes")
#     elif n[::-1]==m:
#         print("Yes")
#     elif n[1:]==m[1:]:
#         print("Yes")
#     else:
#         t=n[::-1]
#         if t[1:]==m[1:]:
#             print("Yes")
#         else:
#             print("No")

for _ in range(int(input())):
    n,m=input().split(" ")
    if n==m:
        print("Yes")
    elif n[::-1] == m:
        print("Yes")
    elif n[1:]==m[1:]:
        print("Yes")
    else:
        print("No")
        