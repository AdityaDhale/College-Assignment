# Sorting First Year Percentage
# Quick Sort in Ascending Order
# Display Top Five Scores


# Function to display percentages
def display_percentages(percentages):

    print("\n--------------------------------------------")
    print("Student Percentages")
    print("--------------------------------------------")

    for i in range(len(percentages)):
        print("Student", i + 1, ":", percentages[i])

    print("--------------------------------------------")


# Function to partition the array
def partition(percentages, low, high):

    # Select the last element as pivot
    pivot = percentages[high]

    i = low - 1

    for j in range(low, high):

        # Arrange smaller elements before pivot
        if percentages[j] <= pivot:

            i = i + 1

            # Swap elements
            temp = percentages[i]
            percentages[i] = percentages[j]
            percentages[j] = temp

    # Place pivot at correct position
    temp = percentages[i + 1]
    percentages[i + 1] = percentages[high]
    percentages[high] = temp

    return i + 1


# Function for Quick Sort
def quick_sort(percentages, low, high):

    if low < high:

        # Find pivot position
        pivot_position = partition(percentages, low, high)

        # Sort left part
        quick_sort(percentages, low, pivot_position - 1)

        # Sort right part
        quick_sort(percentages, pivot_position + 1, high)


# Function to display top five scores
def display_top_five(percentages):

    print("\n--------------------------------------------")
    print("Top Five Scores")
    print("--------------------------------------------")

    n = len(percentages)

    if n < 5:

        print("There are less than 5 students.")

        # Display all available scores
        for i in range(n):

            # Highest scores are at the end
            rank = i + 1
            position = n - i - 1

            print("Rank", rank, ":", percentages[position])

    else:

        # Since array is in ascending order,
        # highest values are at the end

        for i in range(5):

            position = n - i - 1

            print("Rank", i + 1, ":", percentages[position])


# Main Program

print("==============================================")
print("       FIRST YEAR PERCENTAGE")
print("          QUICK SORT PROGRAM")
print("==============================================")


# Input number of students
n = int(input("\nEnter number of students: "))


# Create empty list
percentages = []


# Input percentages
print("\nEnter first year percentage of students:")

for i in range(n):

    percentage = float(
        input("Enter percentage of student " + str(i + 1) + ": ")
    )

    percentages.append(percentage)


# Display original percentages
print("\nOriginal percentages:")

display_percentages(percentages)


# Perform Quick Sort
quick_sort(percentages, 0, len(percentages) - 1)


# Display sorted percentages
print("\nPercentages after Quick Sort in Ascending Order:")

display_percentages(percentages)


# Display top five scores
display_top_five(percentages)


# End of program
print("\n==============================================")
print("Program completed successfully.")
print("==============================================")