f= open("input.txt","r")
reader= f.read()

# Convert the input string into a 2D grid of integers
grid = [[int(ch) for ch in line] for line in reader.split('\n')]

# Initialize a variable to keep track of the total number of visible trees
total_visible = 0

# Iterate through each row and column of the grid
for i in range(len(grid)):
    for j in range(len(grid[i])):
        # Find the tallest tree in the current row or column
        tallest = max(grid[i][j], grid[j][i])
        
        # Check if there are any other trees in the current row or column that are taller
        # If there are no taller trees, then the tallest tree is visible
        if tallest == grid[i][j] and all(t < tallest for t in grid[i]) and i != 0 and i != len(grid)-1:
            total_visible += 1
        elif tallest == grid[j][i] and all(t < tallest for t in grid[j]) and j != 0 and j != len(grid[i])-1:
            total_visible += 1
            
# Print the total number of visible trees
print(total_visible)