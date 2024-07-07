f = open("input.txt","r")
reader = list(map(str,f.read().split("\n")))
reader.pop(-1)


# grid = [['.']*2000] * 2000

# print(len(grid),len(grid[0]))
currPosH = [0,0]
currPosT = [0,0]

all_pos = []
all_pos.append((0,0))
score =0
for instruct in reader :
    direction, movement = instruct.split(" ")
    movement = int(movement)

    if direction == 'U':
        for i in range(0,movement):
            tmp = currPosH 
            
            if currPosH == currPosT :
                currPosH[0] -=1
                all_pos.append(currPosT)
                continue
            elif currPosT[1] == currPosH[1]:
                currPosH[0] -=1
                currPosT[0] -=1
                all_pos.append(currPosT)

    if direction == 'R' :
        for i in range(0,movement):
            tmp = currPosH
            if currPosH == currPosT :
                currPosH[1] +=1
                all_pos.append(currPosT)
                continue

            elif currPosT[0] == currPosH[0]:
                currPosH[1] +=1
                currPosT[1] +=1

    if(direction == 'D') :
        for i in range(0,movement):
            tmp = currPosH
            if currPosH == currPosT :
                currPosH[0] +=1
                all_pos.append(currPosT)
                continue
            elif:
                currPosH[0] +=1
                currPosT[0] +=1
                all_pos.append(currPosT)

    if(direction == 'L') :
        for i in range(0,movement):
            tmp = currPosH
            score +=1 
            if currPosH == currPosT :
                currPosH[1] -=1
                all_pos.append(currPosT)
                continue
            else :
                currPosH[-1] -=1
            
            if(currPosT[0] == currPosH[0]):
                currPosT[1]-=1
            else:
                currPosT = tmp

            all_pos.append(currPosT)

points = set(tuple(i) for i in all_pos)
print(points)
print(score)