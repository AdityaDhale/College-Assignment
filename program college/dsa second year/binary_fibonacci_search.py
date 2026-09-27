# Searching and Sorting
# Binary Search and Fibonacci Search


# Function to sort roll numbers
def sort_roll_numbers(roll_numbers):

    n = len(roll_numbers)

    # Bubble Sort
    for i in range(n - 1):

        for j in range(n - i - 1):

            if roll_numbers[j] > roll_numbers[j + 1]:

                temp = roll_numbers[j]
                roll_numbers[j] = roll_numbers[j + 1]
                roll_numbers[j + 1] = temp

    return roll_numbers


# Function to display roll numbers
def display_roll_numbers(roll_numbers):

    print("\n--------------------------------------------")
    print("Roll Numbers of Students")
    print("--------------------------------------------")

    for i in range(len(roll_numbers)):
        print("Position", i + 1, ":", roll_numbers[i])

    print("--------------------------------------------")


# Function for Binary Search
def binary_search(roll_numbers, key):

    low = 0
    high = len(roll_numbers) - 1

    while low <= high:

        mid = (low + high) // 2

        if roll_numbers[mid] == key:

            return mid

        elif roll_numbers[mid] < key:

            low = mid + 1

        else:

            high = mid - 1

    return -1


# Function for Fibonacci Search
def fibonacci_search(roll_numbers, key):

    n = len(roll_numbers)

    # Fibonacci numbers
    fib1 = 0
    fib2 = 1
    fib3 = fib1 + fib2

    # Find the smallest Fibonacci number
    # greater than or equal to n
    while fib3 < n:

        fib1 = fib2
        fib2 = fib3
        fib3 = fib1 + fib2

    offset = -1

    while fib3 > 1:

        i = offset + fib1

        if i >= n:
            i = n - 1

        if roll_numbers[i] < key:

            fib3 = fib2
            fib2 = fib1
            fib1 = fib3 - fib2

            offset = i

        elif roll_numbers[i] > key:

            fib3 = fib1
            fib2 = fib2 - fib1
            fib1 = fib3 - fib2

        else:

            return i

    # Check the last element
    if fib2 == 1 and offset + 1 < n:
        if roll_numbers[offset + 1] == key:
            return offset + 1

    return -1


# Main Program

print("==============================================")
print("       STUDENT TRAINING PROGRAM")
print("       ROLL NUMBER SEARCH SYSTEM")
print("==============================================")


# Input number of students
n = int(input("\nEnter number of students: "))


# Create an empty list
roll_numbers = []


# Input roll numbers
print("\nEnter roll numbers of students:")

for i in range(n):

    roll = int(input("Enter roll number " + str(i + 1) + ": "))

    roll_numbers.append(roll)


# Display original roll numbers
print("\nOriginal roll numbers entered by students:")

for i in range(len(roll_numbers)):

    print(roll_numbers[i], end=" ")


# Sort roll numbers
roll_numbers = sort_roll_numbers(roll_numbers)


# Display sorted roll numbers
print("\n\nRoll numbers after sorting:")

display_roll_numbers(roll_numbers)


# Menu-driven program
while True:

    print("\n==============================================")
    print("                 SEARCH MENU")
    print("==============================================")
    print("1. Display Sorted Roll Numbers")
    print("2. Search using Binary Search")
    print("3. Search using Fibonacci Search")
    print("4. Exit")
    print("==============================================")

    choice = int(input("Enter your choice: "))


    # Option 1: Display
    if choice == 1:

        display_roll_numbers(roll_numbers)


    # Option 2: Binary Search
    elif choice == 2:

        key = int(input("\nEnter roll number to search: "))

        result = binary_search(roll_numbers, key)

        if result != -1:

            print("\nRoll number found!")
            print("Roll Number:", key)
            print("Position:", result + 1)
            print("Student attended the training program.")

        else:

            print("\nRoll number not found.")
            print("Student did not attend the training program.")


    # Option 3: Fibonacci Search
    elif choice == 3:

        key = int(input("\nEnter roll number to search: "))

        result = fibonacci_search(roll_numbers, key)

        if result != -1:

            print("\nRoll number found!")
            print("Roll Number:", key)
            print("Position:", result + 1)
            print("Student attended the training program.")

        else:

            print("\nRoll number not found.")
            print("Student did not attend the training program.")


    # Option 4: Exit
    elif choice == 4:

        print("\n==============================================")
        print("Thank you!")
        print("Program terminated successfully.")
        print("==============================================")

        break


    # Invalid choice
    else:

        print("\nInvalid choice!")
        print("Please enter a number between 1 and 4.")