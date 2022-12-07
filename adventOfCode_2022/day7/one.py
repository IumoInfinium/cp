f = open("input.txt","r")
generated_cmds = open("cmds.txt","w")
terminal_output  = f.readlines()

cmds = ["#" ,"$ cd .." ,"$ cd /" ,"$ cd" ,"$ ls"]
#        0       1         2         3      4
all_dirs =[]
def startwith(line: str):
    for cmd in cmds :
        if(line.startswith(cmd)):
            return cmds.index(cmd)

for line in terminal_output:
    line =line.strip("\n").strip()
    
    if(line.startswith("$")):
        generated_cmds.write(line[2:] +"\n")

f.close()
generated_cmds.close()
