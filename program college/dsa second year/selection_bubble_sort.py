# Sorting First Year Percentage
# Selection Sort and Bubble Sort


# Function to display percentages
def display_percentages(percentages):
    print("\n--------------------------------------------")
    print("Student Percentages")
    print("--------------------------------------------")

    for i in range(len(percentages)):
        print("Student", i + 1, ":", percentages[i])


# Function for Selection Sort
def selection_sort(percentages):

    n = len(percentages)

    for i in range(n - 1):

        # Assume current position has the largest value
        max_position = i

        for j in range(i + 1, n):

            if percentages[j] > percentages[max_position]:
                max_position = j

        # Swap values
        temp = percentages[i]
        percentages[i] = percentages[max_position]
        percentages[max_position] = temp

    return percentages


# Function for Bubble Sort
def bubble_sort(percentages):

    n = len(percentages)

    for i in range(n - 1):

        for j in range(n - i - 1):

            # Sort in descending order
            if percentages[j] < percentages[j + 1]:

                temp = percentages[j]
                percentages[j] = percentages[j + 1]
                percentages[j + 1] = temp

    return percentages


# Function to display top five scores
def display_top_five(percentages):

    print("\n--------------------------------------------")
    print("Top Five Scores")
    print("--------------------------------------------")

    if len(percentages) < 5:

        print("There are less than 5 students.")

        for i in range(len(percentages)):
            print(i + 1, ":", percentages[i])

    else:

        for i in range(5):
            print("Rank", i + 1, ":", percentages[i])


# Main Program

print("==============================================")
print("       FIRST YEAR STUDENT PERCENTAGE")
print("             SORTING PROGRAM")
print("==============================================")


# Input number of students
n = int(input("\nEnter number of students: "))


# Create empty list
percentages = []


# Input percentages
print("\nEnter percentage of each student:")

for i in range(n):

    percentage = float(
        input("Enter percentage of student " + str(i + 1) + ": ")
    )

    percentages.append(percentage)


# Display original percentages
print("\nOriginal percentages:")

display_percentages(percentages)


# Menu
while True:

    print("\n==============================================")
    print("                 SORTING MENU")
    print("==============================================")
    print("1. Selection Sort")
    print("2. Bubble Sort")
    print("3. Display Top Five Scores")
    print("4. Display All Percentages")
    print("5. Exit")
    print("==============================================")

    choice = int(input("Enter your choice: "))


    # Selection Sort
    if choice == 1:

        selection_sort(percentages)

        print("\nPercentages after Selection Sort:")
        display_percentages(percentages)

        display_top_five(percentages)


    # Bubble Sort
    elif choice == 2:

        bubble_sort(percentages)

        print("\nPercentages after Bubble Sort:")
        display_percentages(percentages)

        display_top_five(percentages)


    # Display Top Five
    elif choice == 3:

        # First sort the percentages
        bubble_sort(percentages)

        display_top_five(percentages)


    # Display all percentages
    elif choice == 4:

        display_percentages(percentages)


    # Exit
    elif choice == 5:

        print("\n==============================================")
        print("Program terminated successfully.")
        print("Thank you!")
        print("==============================================")

        break


    # Invalid choice
    else:

        print("\nInvalid choice!")
        print("Please enter a number between 1 and 5.")