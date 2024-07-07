f = open("input.txt","r")
reader = f.readlines()

score=0

def give_priority(c):
    if c>='a' and c<='z':
        return ord(c)-ord('a') +1
    else:
        return ord(c)-ord('A')+27
s = [
    "vJrwpWtwJgWrhcsFMMfFFhFp",
    "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
    "PmmdzqPrVvPwwTWBwg",
    "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
    "ttgJtRGJQctTZtZT",
    "CrZsJsPPZsGzwwsLwLmpwMDw",
]
for line in s:
    line = line.strip("").strip("\n")
    dict={}
    for i in range(0,len(line)//2):
        if line[i] not in dict.keys():
            dict[line[i]]=1
        else:
            dict[line[i]]+=1
    make_sure=set()
    for i in range(len(line)//2,len(line)):
        if line[i] in dict.keys() and line[i] not in make_sure:
            x = give_priority(line[i])
            print(x)
            score += x
            make_sure.add(line[i])

print(score)