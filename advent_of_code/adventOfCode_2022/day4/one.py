f = open("input.txt","r")
pairs = f.readlines()

score = 0
s = [
    "2-4,6-8",
    "2-3,4-5",
    "5-7,7-9",
    "2-8,3-7",
    "6-6,4-6",
    "2-6,4-8",

]
for pair in pairs:
    pair = pair.strip("\n").strip(" ").split(",")

    A = list(map(int,pair[0].split("-")))
    B = list(map(int,pair[1].split("-")))
    print(A, " ------- ", B)
    
    if((B[0] >= A[0] and B[1] <= A[1]) or
       (A[0] >= B[0] and A[1] <= B[1])):
        score +=1
    continue

print(score)