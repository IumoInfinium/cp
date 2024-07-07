f= open("input.txt","r")

data_stream = f.readlines()[0].strip("\n")
# print(data_stream)
# data_stream = "mjqjpqmgbljsphdztnvjfqwrcgsmlb"
recent_char = []

for i in range(len(data_stream)):
    recent_char.append(data_stream[i])

    if( len(recent_char))>4:
        recent_char.pop(0)

    if(len(set(recent_char))== 4):
        print(i+1)
        break
