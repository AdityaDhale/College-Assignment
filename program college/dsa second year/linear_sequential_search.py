# Searching and Sorting
# Searching Roll Numbers using Linear Search and Sentinel Search


# Function to display roll numbers
def display_roll_numbers(roll_numbers):
    print("\n----------------------------------------")
    print("Roll Numbers of Students")
    print("----------------------------------------")

    for i in range(len(roll_numbers)):
        print("Position", i + 1, ":", roll_numbers[i])

    print("----------------------------------------")


# Function for Linear Search
def linear_search(roll_numbers, key):
    for i in range(len(roll_numbers)):
        if roll_numbers[i] == key:
            return i

    return -1


# Function for Sentinel Search
def sentinel_search(roll_numbers, key):

    n = len(roll_numbers)

    # Store last element
    last = roll_numbers[n - 1]

    # Put search element at last position
    roll_numbers[n - 1] = key

    i = 0

    # Search for the element
    while roll_numbers[i] != key:
        i = i + 1

    # Restore original last element
    roll_numbers[n - 1] = last

    # Check whether element was actually found
    if i < n - 1 or last == key:
        return i
    else:
        return -1


# Main Program

print("============================================")
print("       STUDENT TRAINING PROGRAM")
print("       ROLL NUMBER SEARCH SYSTEM")
print("============================================")

# Input number of students
n = int(input("\nEnter number of students: "))

# Create empty list
roll_numbers = []

# Input roll numbers
print("\nEnter roll numbers of students:")

for i in range(n):
    roll = int(input("Enter roll number " + str(i + 1) + ": "))
    roll_numbers.append(roll)


# Display entered roll numbers
display_roll_numbers(roll_numbers)


# Menu driven program
while True:

    print("\n============================================")
    print("              SEARCH MENU")
    print("============================================")
    print("1. Display Roll Numbers")
    print("2. Search using Linear Search")
    print("3. Search using Sentinel Search")
    print("4. Exit")
    print("============================================")

    choice = int(input("Enter your choice: "))

    # Option 1
    if choice == 1:

        display_roll_numbers(roll_numbers)


    # Option 2
    elif choice == 2:

        key = int(input("\nEnter roll number to search: "))

        result = linear_search(roll_numbers, key)

        if result != -1:

            print("\nRoll number found!")
            print("Roll Number:", key)
            print("Position:", result + 1)

        else:

            print("\nRoll number not found.")
            print("Student did not attend the training program.")


    # Option 3
    elif choice == 3:

        key = int(input("\nEnter roll number to search: "))

        result = sentinel_search(roll_numbers, key)

        if result != -1:

            print("\nRoll number found!")
            print("Roll Number:", key)
            print("Position:", result + 1)

        else:

            print("\nRoll number not found.")
            print("Student did not attend the training program.")


    # Option 4
    elif choice == 4:

        print("\nThank you!")
        print("Program terminated.")
        break


    # Invalid choice
    else:

        print("\nInvalid choice!")
        print("Please enter a number between 1 and 4.")