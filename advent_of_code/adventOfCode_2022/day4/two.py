f = open("input.txt","r")
pairs = f.readlines()

s = [
    "2-4,6-8",
    "2-3,4-5",
    "5-7,7-9",
    "2-8,3-7",
    "6-6,4-6",
    "2-6,4-8",

]
pairs_overlaping=0
for pair in pairs:
    pair = pair.strip("\n").strip(" ").split(",")

    A = list(map(int,pair[0].split("-")))
    B = list(map(int,pair[1].split("-")))
    # print(A, " ------- ", B)

    # if(
    #     max(A[1], B[1]) - min(A[0], B[0]) < (A[1] - A[0]) + (B[1] - B[0])
    # ):
    #     pairs_overlaping+=1

    if (max(A[0],B[0]) <= min(A[1],B[1])):
        pairs_overlaping +=1
print(pairs_overlaping)