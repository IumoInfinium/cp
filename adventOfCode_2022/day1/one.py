f = open('input.txt','r')
reader = f.readlines()
l=[]
curr=0
for line in reader:
    if(line == "\n"):
        l.append(curr) 
        curr= 0;
        continue;     
    line= line.strip("\n")
    print(line)  
    curr+= int(line)
l= sorted(l)
print(max(l))
print(l[-1]+l[-2]+l[-3])