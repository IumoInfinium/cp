reader = open("input.txt","r").read().split("\n")
reader.pop(-1)

# print(reader)

x=1
cycles = [x]
for line in reader:
    if line.startswith("addx"):
        cycles.append(x)
        cycles.append(x)
        addx, val = line.split()
        x += int(val)
    
    if line.startswith("noop"):
        cycles.append(x)

checkpoints = [20, 60 ,100, 140, 180, 220]
signal_strength = 0
for c in checkpoints:
    signal_strength += c * cycles[c]

print(signal_strength)