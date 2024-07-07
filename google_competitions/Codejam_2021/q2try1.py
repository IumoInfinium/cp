##Moons And Umbrellas
t = int(input())
for i in range(t):
    X,Y,s = input().split(" ")
    X= int(X)
    Y= int(Y)
    n= len(s)
    poss= []
    for j in range(n):
        if s[j] == "?":
            if s[j-1:j+1] == "J":

