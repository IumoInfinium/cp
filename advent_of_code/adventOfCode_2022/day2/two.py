f = open("input.txt","r")
reader = f.readlines()


cost = {
    'A' : 1,  #roock
    'B' : 2,  #paper
    'C' : 3,  #s
    'X' : 1,  #r
    'Y' : 2,  #p
    'Z' : 3    #s
}

match_stats=[0,3,6]

score =0 
for line in reader:
    if(line == "\n"):
        continue
    line = line.strip("\n")
    a,b = line.split(" ")
    if(a == "A" and b == "X"):
        score += 3
    
    if(a == "A" and b == "Y"):
        score += 1 + 3
    
    if(a == "A" and b == "Z"):
        score += 2 + 6
    

    if(a == "B" and b == "X"):
        score += 1 
    
    if(a == "B" and b == "Y"):
        score += 2 + 3
    
    if(a == "B" and b == "Z"):
        score += 3 + 6
    

    if(a == "C" and b == "X"):
        score += 2
    
    if(a == "C" and b == "Y"):
        score += 3 + 3 
    if(a == "C" and b == "Z"):
        score += 1 + 6
    
print( score)