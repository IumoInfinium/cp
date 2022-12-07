f = open("input.txt","r")

terminal_output = f.readlines()

for line in terminal_output:
    line = line.strip("\n").strip("")
    print(line)