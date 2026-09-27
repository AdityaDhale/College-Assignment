# Fundamental of Data Structure
# Store marks of N students and perform various operations

# Input number of students
n = int(input("Enter number of students: "))

marks = {}

# Store marks
for i in range(1, n + 1):
    mark = int(input(f"Enter marks for student {i} (-1 for absent): "))
    marks[i] = mark


# 1. Average score of the class
def average_score(marks):
    total = 0
    present_count = 0

    for mark in marks.values():
        if mark != -1:          # Ignore absent students
            total += mark
            present_count += 1

    if present_count == 0:
        return 0

    return total / present_count


# 2. Highest and lowest score
def highest_lowest(marks):
    present_marks = []

    for mark in marks.values():
        if mark != -1:
            present_marks.append(mark)

    if len(present_marks) == 0:
        return None, None

    highest = present_marks[0]
    lowest = present_marks[0]

    for mark in present_marks:
        if mark > highest:
            highest = mark
        if mark < lowest:
            lowest = mark

    return highest, lowest


# 3. Count absent students
def count_absent(marks):
    count = 0

    for mark in marks.values():
        if mark == -1:
            count += 1

    return count


# 4. Display marks with frequency
def display_frequency(marks):
    frequency = {}

    for mark in marks.values():
        if mark != -1:
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1

    print("\nMarks Frequency:")
    for mark, count in sorted(frequency.items()):
        print(f"Marks: {mark} -> Frequency: {count}")


# Perform operations
avg = average_score(marks)
highest, lowest = highest_lowest(marks)
absent = count_absent(marks)

print("\n----- Results -----")

print(f"Average Score: {avg:.2f}")

if highest is not None:
    print(f"Highest Score: {highest}")
    print(f"Lowest Score: {lowest}")
else:
    print("No student was present.")

print(f"Number of Absent Students: {absent}")

display_frequency(marks)
