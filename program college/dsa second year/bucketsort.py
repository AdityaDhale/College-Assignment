# Bucket Sort
# Sort a list of names based on the length of names


# Function to display names
def display_names(names):
    print("\n--------------------------------------------")
    print("List of Names")
    print("--------------------------------------------")

    for i in range(len(names)):
        print(i + 1, ".", names[i])


# Function to find the maximum length of name
def find_max_length(names):

    max_length = 0

    for i in range(len(names)):

        if len(names[i]) > max_length:
            max_length = len(names[i])

    return max_length


# Function for Bucket Sort
def bucket_sort(names):

    # Find maximum name length
    max_length = find_max_length(names)

    # Create buckets
    buckets = []

    for i in range(max_length + 1):
        buckets.append([])

    # Put each name into its bucket
    # according to its length
    for i in range(len(names)):

        length = len(names[i])

        buckets[length].append(names[i])

    # Create sorted list
    sorted_names = []

    # Collect names from buckets
    # starting from smallest length
    for i in range(max_length + 1):

        for j in range(len(buckets[i])):

            sorted_names.append(buckets[i][j])

    return sorted_names


# Main Program

print("==============================================")
print("       NAME LENGTH BUCKET SORT")
print("==============================================")


# Input number of names
n = int(input("\nEnter number of names: "))


# Create empty list
names = []


# Input names
print("\nEnter names:")

for i in range(n):

    name = input("Enter name " + str(i + 1) + ": ")

    names.append(name)


# Display original list
print("\nOriginal List:")

display_names(names)


# Display length of each name
print("\n--------------------------------------------")
print("Length of Each Name")
print("--------------------------------------------")

for i in range(len(names)):

    print(names[i], "=", len(names[i]), "characters")


# Perform Bucket Sort
sorted_names = bucket_sort(names)


# Display sorted list
print("\nNames after Bucket Sort:")
display_names(sorted_names)


# Display names according to length
print("\n--------------------------------------------")
print("Names Sorted According to Length")
print("--------------------------------------------")

for i in range(len(sorted_names)):

    print(
        "Name:", sorted_names[i],
        "   Length:", len(sorted_names[i])
    )


print("\n==============================================")
print("Program completed successfully.")
print("==============================================")