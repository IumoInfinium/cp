tree = {
    '/': {
        'a': {
            'e': {
                'i': 584
            },
            'f': 29116,
            'g': 2557,
            'h.lst': 62596
        },
        'b.txt': 14848514,
        'c.dat': 8504156,
        'd': {
            'j': 4060174,
            'd.log': 8033020,
            'd.ext': 5626152,
            'k': 7214296
        }
    }
}

def get_total_size(tree, directory):
    total_size = 0
    for item in tree[directory]:
        if isinstance(tree[directory][item], dict):
            # The item is a directory, so get its total size.
            total_size += get_total_size(tree, tree[directory][item])
        else:
            # The item is a file, so add its size to the total.
            total_size += tree[directory][item]
    return total_size

directories = []
for directory in tree:
    total_size = get_total_size(tree, directory)
    if total_size <= 100000:
        directories.append(directory)

# Calculate the sum of the total sizes of the directories found above.
total_sum = 0
for directory in directories:
    total_sum += get_total_size(tree, directory)

# Print the result.
print(total_sum)