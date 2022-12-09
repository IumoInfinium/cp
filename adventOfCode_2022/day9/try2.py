f = open("input.txt","r")
lines =list(map(str,f.read().split("\n")))
lines.pop(-1)

stateH = [0,0]
stateT = [0,0]
pos = []

def calculate_tail_position(head_moves):
  # Initialize the head and tail positions to the starting position
  head_position = [0, 0]
  tail_position = [0, 0]

  # Loop through each movement for the head
  for move in head_moves:
    # Update the position of the head based on the current move
    if move[0] == 'U':
      head_position[1] -= 1
    elif move[0] == 'D':
      head_position[1] += 1
    elif move[0] == 'L':
      head_position[0] -= 1
    elif move[0] == 'R':
      head_position[0] += 1

    # Check if the head and tail are adjacent and not in the same row or column
    if (abs(head_position[0] - tail_position[0]) > 1 or abs(head_position[1] - tail_position[1]) > 1) and (head_position[0] != tail_position[0] and head_position[1] != tail_position[1]):
      # If the head is above and to the left of the tail, the tail moves diagonally up and to the left
      if head_position[0] < tail_position[0] and head_position[1] < tail_position[1]:
        tail_position[0] -= 1
        tail_position[1] -= 1
      # If the head is above and to the right of the tail, the tail moves diagonally up and to the right
      elif head_position[0] > tail_position[0] and head_position[1] < tail_position[1]:
        tail_position[0] += 1
        tail_position[1] -= 1
      # If the head is below and to the left of the tail, the tail moves diagonally down and to the left
      elif head_position[0] < tail_position[0] and head_position[1] > tail_position[1]:
        tail_position[0] -= 1
        tail_position[1] += 1
      # If the head is below and to the right of the tail, the tail moves diagonally down and to the right
      elif head_position[0] > tail_position[0] and head_position[1] > tail_position[1]:
        tail_position[0] += 1
        tail_position[1] += 1

    # If the head is not adjacent to the tail, the tail moves one step in the same direction as the head
    elif abs(head_position[0] - tail_position[0]) > 1 or abs(head_position[1] - tail_position[1]) > 1:
      if move[0] == 'U':
        tail_position[1] -= 1
      elif move[0] == 'D':
        tail_position[1] += 1
      elif move[0] == 'L':
        tail_position[0] -= 1
      elif move[0] == 'R':
        tail_position[0] += 1

  # Return the final position of the tail
  return tail_position

for line in lines:
    head_moves = list(map(str,line.split(" ")))
    head_moves[-1] = int(head_moves)