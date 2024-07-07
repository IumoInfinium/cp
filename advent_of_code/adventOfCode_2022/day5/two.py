f = open("input.txt","r")
reader = f.readlines()

stacks =[
    ["S","C","V","N"],
    ["Z","M","J","H","N","S"],
    ["M","C","T","G","J","N","D"],
    ["T","D","F","J","W","R","M"],
    ["P","F","H"],
    ["C","T","Z","H","J"],
    ["D","P","R","Q","F","S","L","Z"],
    ["C","S","L","H","D","F","P","W"],
    ["D","S","M","P","F","N","G","Z"]
]
operations = reader[10:]


for instruction in operations:
    l = instruction.strip("\n").split(" ")
    s = int(l[1])
    src = int(l[-3])
    dest = int(l[-1])
    
    aux = []
    while(s > 0 and len(stacks[src-1])>0):
        t = stacks[src-1].pop()
        aux.append(t)
        s -=1
    stacks[dest-1] += reversed(aux)

ans=""
for stack in stacks:
    if(len(stack)>0):
        ans += stack[-1]
print(ans)